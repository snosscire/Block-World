#ifndef __BADENGINE_DEFAULTMOVINGBEHAVIOR_H__
#define __BADENGINE_DEFAULTMOVINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BadEngine {
	class GameObject;
	class DefaultMovingBehavior : public ObjectBehavior {
		public:
			DefaultMovingBehavior();
			virtual ~DefaultMovingBehavior();
			void perform(GameObject& object, unsigned int deltaTime);
	};
};

#endif // __BADENGINE_DEFAULTMOVINGBEHAVIOR_H__
