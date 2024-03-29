#ifndef __BLOCKWORLD_GIB_H__
#define __BLOCKWORLD_GIB_H__

#include "../GameObject.h"

#include "../../Engine/Engine.h"
#include "../../Engine/Image.h"

using namespace BadEngine;

namespace BlockWorld {
	class Gib : public GameObject {
		private:
			void initialize(Engine& engine, Image* image, double x, double y);
		
		public:
			Gib(Engine& engine, Image* image, World& world, double x, double y);
			virtual ~Gib();
	};
};

#endif // __BLOCKWORLD_GIB_H__
