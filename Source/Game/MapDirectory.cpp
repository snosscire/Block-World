#include "MapDirectory.h"

namespace BlockWorld {
	MapDirectory::MapDirectory() :
		m_directoryName(),
		m_directoryPath(),
		m_imagePath(),
		m_xmlPath(),
		m_name(),
		m_description()
	{
	}
	
	MapDirectory::MapDirectory(string directoryPath, string directoryName, string imagePath) :
		m_directoryName(directoryName),
		m_directoryPath(directoryPath),
		m_imagePath(imagePath),
		m_xmlPath(),
		m_name(),
		m_description()
	{
		m_name = directoryName;
	}
	
	MapDirectory::~MapDirectory()
	{
	}
	
	string& MapDirectory::getPath()
	{
		return m_directoryPath;
	}
	
	string& MapDirectory::getImagePath()
	{
		return m_imagePath;
	}
	
	string& MapDirectory::getXMLPath()
	{
		return m_xmlPath;
	}
	
	string& MapDirectory::getName()
	{
		return m_name;
	}
	
	string& MapDirectory::getDescription()
	{
		return m_description;
	}
	
	void MapDirectory::setXMLPath(string path)
	{
		m_xmlPath = path;
	}
	
	bool MapDirectory::hasXML()
	{
		if (m_xmlPath.length() > 0)
			return true;
		return false;
	}
};
