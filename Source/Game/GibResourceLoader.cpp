#include "GibResourceLoader.h"

#include "../External/tinyxml2/tinyxml2.h"

#include <iostream>
#include <sstream>

using namespace tinyxml2;

namespace BlockWorld {
	GibResourceLoader::GibResourceLoader() :
		m_engine(NULL),
		m_skulls(),
		m_gibs()
	{
	}
	
	GibResourceLoader::GibResourceLoader(Engine& engine) :
		m_engine(&engine),
		m_skulls(),
		m_gibs()
	{
	}
	
	GibResourceLoader::~GibResourceLoader()
	{
	}
	
	void GibResourceLoader::loadFile(const char* path)
	{
		XMLDocument document;
		if (document.LoadFile(path) == XML_NO_ERROR) {
			XMLElement* file = document.FirstChildElement("file");
			if (file) {
				XMLElement* skulls = file->FirstChildElement("skulls");
				
				if (skulls) {
					XMLElement* skull = skulls->FirstChildElement("skull");
				
					while (skull) {
						const char* value = skull->Attribute("image");
						if (value) {
							ostringstream image;
							image << "Resources/Gibs/" << value;
							m_skulls.push_back(image.str());
						}
					
						skull = skull->NextSiblingElement("skull");
					}
				}
				
				XMLElement* gibs = file->FirstChildElement("gibs");
				
				if (gibs) {
					XMLElement* gib = gibs->FirstChildElement("gib");
				
					while (gib) {
						const char* value = gib->Attribute("image");
						if (value) {
							ostringstream image;
							image << "Resources/Gibs/" << value;
							m_gibs.push_back(image.str());
						}
					
						gib = gib->NextSiblingElement("gib");
					}
				}
			}
		} else {
			cout << document.GetErrorStr1() << endl;
			cout << document.GetErrorStr2() << endl;
		}
	}
	
	const char* GibResourceLoader::getRandomSkull()
	{
		if (!m_skulls.empty()) {
			int min = 0;
			int max = m_skulls.size() - 1;
			int number = m_engine->getRandomNumber(min, max);
			return m_skulls[number].c_str();
		}
		return NULL;
	}
	
	const char* GibResourceLoader::getRandomGib()
	{
		if (!m_gibs.empty()) {
			int min = 0;
			int max = m_gibs.size() - 1;
			int number = m_engine->getRandomNumber(min, max);
			return m_gibs[number].c_str();
		}
		return NULL;			
	}
};
