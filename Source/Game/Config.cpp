#include "Config.h"
#include "BlockWorld.h"

#include "../External/tinyxml2/tinyxml2.h"

#include <iostream>

using namespace std;
using namespace tinyxml2;

namespace BlockWorld {
	double Config::DefaultGravity = 4.0;
	
	double Config::PlayerMoveSpeed = 2.0;
	double Config::PlayerJumpSpeed = 8.0;
	
	double Config::MaxCrosshairDistance = 180.0;
	
	/* Gibs and Blood */
	unsigned int Config::MaxGibsOnScreen = 1000;
	int Config::SkullSpawnChance = 3;
	int Config::GibsMin = 1;
	int Config::GibsMax = 3;
	int Config::BloodParticles = 100;
	int Config::BloodParticlesSpread = 6;
	int Config::GibMaxSpeedX = 8;
	int Config::GibMaxSpeedY = 8;
	int Config::BloodMaxSpeedX = 4;
	int Config::BloodMaxSpeedY = 4;
	
	bool Config::DrawHitBoxes = false;
	
	void Config::loadFile(const string& path)
	{
		XMLDocument document;
		if (document.LoadFile(path.c_str()) == XML_NO_ERROR) {
			XMLElement* file = document.FirstChildElement("file");
			if (file) {
				XMLElement* config = file->FirstChildElement("config");
				
				while (config) {
					const char* name = config->Attribute("name");
					if (name) {
						     if (strcmp(name, "DefaultGravity") == 0)       config->QueryDoubleAttribute("value", &Config::DefaultGravity);
						else if (strcmp(name, "PlayerMoveSpeed") == 0)      config->QueryDoubleAttribute("value", &Config::PlayerMoveSpeed);
						else if (strcmp(name, "PlayerJumpSpeed") == 0)      config->QueryDoubleAttribute("value", &Config::PlayerJumpSpeed);
						else if (strcmp(name, "MaxCrosshairDistance") == 0) config->QueryDoubleAttribute("value", &Config::MaxCrosshairDistance);
						else if (strcmp(name, "MaxGibsOnScreen") == 0)      config->QueryUnsignedAttribute("value", &Config::MaxGibsOnScreen);
						else if (strcmp(name, "GibsMin") == 0)              config->QueryIntAttribute("value", &Config::GibsMin);
						else if (strcmp(name, "GibsMax") == 0)              config->QueryIntAttribute("value", &Config::GibsMax);
						else if (strcmp(name, "BloodParticles") == 0)       config->QueryIntAttribute("value", &Config::BloodParticles);
						else if (strcmp(name, "GibMaxSpeedX") == 0)         config->QueryIntAttribute("value", &Config::GibMaxSpeedX);
						else if (strcmp(name, "GibMaxSpeedY") == 0)         config->QueryIntAttribute("value", &Config::GibMaxSpeedY);
						else if (strcmp(name, "BloodMaxSpeedX") == 0)       config->QueryIntAttribute("value", &Config::BloodMaxSpeedX);
						else if (strcmp(name, "BloodMaxSpeedY") == 0)       config->QueryIntAttribute("value", &Config::BloodMaxSpeedY);
					}
					
					config = config->NextSiblingElement("config");
				}
			}
		} else {
			cout << document.GetErrorStr1() << endl;
			cout << document.GetErrorStr2() << endl;
		}
	}
};

