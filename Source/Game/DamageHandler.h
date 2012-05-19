#ifndef __BLOCKWORLD_DAMAGEHANDLER_H__
#define __BLOCKWORLD_DAMAGEHANDLER_H__

namespace BlockWorld {
	class GameObject;
	class DamageHandler {
		public:
			virtual void handleDamage(GameObject* object, int damage) = 0;
	};
};

#endif
