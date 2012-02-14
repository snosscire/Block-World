#ifndef __BADENGINE_DEFAULTCOLLIDINGBEHAVIOR_H__
#define __BADENGINE_DEFAULTCOLLIDINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BadEngine {
	class GameObject;
	class DefaultCollidingBehavior : public ObjectBehavior {
		public:
			DefaultCollidingBehavior();
			virtual ~DefaultCollidingBehavior();
			void perform(GameObject& object, unsigned int deltaTime);
	};
};

#endif // __BADENGINE_DEFAULTCOLLIDINGBEHAVIOR_H__
