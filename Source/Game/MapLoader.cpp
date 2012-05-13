#include "MapLoader.h"
#include "MapDirectory.h"

#include "../External/aphex/aphex.h"

#include <iostream>
#include <cstring>

namespace BlockWorld {
	MapLoader::MapLoader() :
		m_maps()
	{
	}
	
	MapLoader::~MapLoader()
	{
		list<MapDirectory*>::iterator it;
		it = m_maps.begin();
		for ( ; it != m_maps.end(); it++) {
			MapDirectory* map = *it;
			delete map;
		}
	}
	
	MapDirectory* MapLoader::readMapDirectory(string directoryName, const ostringstream& directoryPath)
	{
		string path = directoryPath.str();
		AphexDirectory* directory = aphex_directory_read((char*)path.c_str());
		MapDirectory* mapDirectory = NULL;
		if (directory) {
			bool foundImage = false;
			bool foundXML = false;
			
			for (unsigned int i = 0; i < directory->size; i++) {
				if (strcmp(directory->contents[i], "map.png") == 0) {
					foundImage = true;
				} else if (strcmp(directory->contents[i], "map.xml") == 0) {
					foundXML = true;
				}
			}
			
			if (foundImage) {
				ostringstream imagePath;
				imagePath << path << "/map.png";
				mapDirectory = new MapDirectory(path, directoryName, imagePath.str());
				if (foundXML) {
					ostringstream xmlPath;
					xmlPath << path << "/map.xml";
					mapDirectory->setXMLPath(xmlPath.str());
				}
			}
			
			aphex_directory_delete(directory);
			directory = NULL;
		}
		return mapDirectory;
	}
	
	void MapLoader::loadDirectory(string path)
	{
		AphexDirectory* baseDirectory = aphex_directory_read((char*)path.c_str());
		if (baseDirectory) {
			for (unsigned int i = 0; i < baseDirectory->size; i++) {
				string directoryName = baseDirectory->contents[i];
				
				ostringstream directoryPath;
				directoryPath << path << "/" << directoryName;
				
				cout << "Map directory: " << directoryPath.str() << endl;
				MapDirectory* mapDirectory = readMapDirectory(directoryName, directoryPath);
				if (mapDirectory) {
					m_maps.push_back(mapDirectory);
				}
			}
			
			aphex_directory_delete(baseDirectory);
			baseDirectory = NULL;
		}
		
		list<MapDirectory*>::iterator it = m_maps.begin();
		for ( ; it != m_maps.end(); it++) {
			MapDirectory* directory = *it;
			cout << "Loaded map: " << directory->getName() << endl;
		}
	}
	
	list<MapDirectory*>& MapLoader::getMaps()
	{
		return m_maps;
	}
};
