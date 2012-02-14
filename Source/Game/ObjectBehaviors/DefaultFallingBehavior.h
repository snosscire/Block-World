#ifndef __BADENGINE_DEFAULTFALLINGBEHAVIOR_H__
#define __BADENGINE_DEFAULTFALLINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BadEngine {
	class GameObject;
	class DefaultFallingBehavior : public ObjectBehavior {
		public:
			DefaultFallingBehavior();
			virtual ~DefaultFallingBehavior();
			void perform(GameObject& object, unsigned int deltaTime);
	};
};

#endif // __BADENGINE_DEFAULTFALLINGBEHAVIOR_H__
