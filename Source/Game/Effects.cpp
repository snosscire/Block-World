#include "Effects.h"
#include "GibResourceLoader.h"
#include "World.h"
#include "GameObject.h"
#include "Objects/Gib.h"
#include "Objects/Blood.h"
#include "Config.h"

#include "../Engine/Image.h"

namespace BlockWorld {
	void Effects::bloodSplash(Engine& engine, GibResourceLoader& gibLoader, deque<GameObject*>& list, World& world, double originX, double originY)
	{
		int number = engine.getRandomNumber(1, Config::SkullSpawnChance);
		if (number == 1) {
			const char* file = gibLoader.getRandomSkull();
			if (file) {
				Image* image = engine.loadImage(file);
				if (image) {
					Gib* skull = new Gib(engine, image, world, originX, originY);
					list.push_back(skull);
				}
			}
		}
		
		int gibs = engine.getRandomNumber(Config::GibsMin, Config::GibsMax);
		for (int i = 0; i < gibs; i++) {
			const char* file = gibLoader.getRandomGib();
			if (file) {
				Image* image = engine.loadImage(file);
				if (image) {
					Gib* gib = new Gib(engine, image, world, originX, originY);
					list.push_back(gib);
				}
			}
		}
		
		for (int i = 0; i < Config::BloodParticles; i++) {
			double x = originX - engine.getRandomNumber(-Config::BloodParticlesSpread, Config::BloodParticlesSpread);
			double y = originY - engine.getRandomNumber(-Config::BloodParticlesSpread, Config::BloodParticlesSpread);
			Blood* blood = new Blood(engine, world, x, y);
			list.push_back(blood);
		}
		
		while (list.size() > Config::MaxGibsOnScreen) {
			GameObject* object = list.front();
			delete object;
			list.pop_front();
		}
	}
};

