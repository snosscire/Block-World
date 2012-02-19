#ifndef __BLOCKWORLD_DEFAULTCOLLIDINGBEHAVIOR_H__
#define __BLOCKWORLD_DEFAULTCOLLIDINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BlockWorld {
	class GameObject;
	class DefaultCollidingBehavior : public ObjectBehavior {
		public:
			DefaultCollidingBehavior();
			virtual ~DefaultCollidingBehavior();
			void perform(GameObject& object, double deltaTime);
	};
};

#endif // __BLOCKWORLD_DEFAULTCOLLIDINGBEHAVIOR_H__
