#ifndef __BLOCKWORLD_BLOOD_H__
#define __BLOCKWORLD_BLOOD_H__

#include "../GameObject.h"

#include "../../Engine/Engine.h"

using namespace BadEngine;

namespace BlockWorld {
	class Blood : public GameObject {
		private:
			void initialize(Engine& engine, double x, double y);
		
		public:
			Blood(Engine& engine, World& world, double x, double y);
			virtual ~Blood();
	};
};

#endif // __BLOCKWORLD_BLOOD_H__
