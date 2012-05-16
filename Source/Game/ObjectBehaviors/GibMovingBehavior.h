#ifndef __BLOCKWORLD_GIBMOVINGBEHAVIOR_H__
#define __BLOCKWORLD_GIBMOVINGBEHAVIOR_H__

#include "../ObjectBehavior.h"

namespace BlockWorld {
	class GameObject;
	class GibMovingBehavior : public ObjectBehavior {
		public:
			GibMovingBehavior();
			virtual ~GibMovingBehavior();
			void perform(GameObject& object, double deltaTime);
	};
};

#endif // __BLOCKWORLD_GIBMOVINGBEHAVIOR_H__
