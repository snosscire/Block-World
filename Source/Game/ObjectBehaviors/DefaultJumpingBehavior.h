#ifndef __BADENGINE_DEFAULTJUMPINGBEHAVIOR_H__
#define __BADENGINE_DEFAULTJUMPINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BadEngine {
	class GameObject;
	class DefaultJumpingBehavior : public ObjectBehavior {
		public:
			DefaultJumpingBehavior();
			virtual ~DefaultJumpingBehavior();
			void perform(GameObject& object, unsigned int deltaTime);
	};
};

#endif // __BADENGINE_DEFAULTJUMPINGGBEHAVIOR_H__
