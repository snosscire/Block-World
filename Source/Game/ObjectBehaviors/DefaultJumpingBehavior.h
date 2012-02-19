#ifndef __BLOCKWORLD_DEFAULTJUMPINGBEHAVIOR_H__
#define __BLOCKWORLD_DEFAULTJUMPINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BlockWorld {
	class GameObject;
	class DefaultJumpingBehavior : public ObjectBehavior {
		public:
			DefaultJumpingBehavior();
			virtual ~DefaultJumpingBehavior();
			void perform(GameObject& object, double deltaTime);
	};
};

#endif // __BLOCKWORLD_DEFAULTJUMPINGGBEHAVIOR_H__
