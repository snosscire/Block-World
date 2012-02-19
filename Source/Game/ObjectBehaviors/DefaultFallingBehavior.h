#ifndef __BLOCKWORLD_DEFAULTFALLINGBEHAVIOR_H__
#define __BLOCKWORLD_DEFAULTFALLINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BlockWorld {
	class GameObject;
	class DefaultFallingBehavior : public ObjectBehavior {
		public:
			DefaultFallingBehavior();
			virtual ~DefaultFallingBehavior();
			void perform(GameObject& object, double deltaTime);
	};
};

#endif // __BLOCKWORLD_DEFAULTFALLINGBEHAVIOR_H__
