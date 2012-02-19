#ifndef __BLOCKWORLD_DEFAULTMOVINGBEHAVIOR_H__
#define __BLOCKWORLD_DEFAULTMOVINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BlockWorld {
	class GameObject;
	class DefaultMovingBehavior : public ObjectBehavior {
		public:
			DefaultMovingBehavior();
			virtual ~DefaultMovingBehavior();
			void perform(GameObject& object, double deltaTime);
	};
};

#endif // __BLOCKWORLD_DEFAULTMOVINGBEHAVIOR_H__
