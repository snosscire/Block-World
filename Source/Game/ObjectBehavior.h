#ifndef __BLOCKWORLD_OBJECTBEHAVIOR_H__
#define __BLOCKWORLD_OBJECTBEHAVIOR_H__

namespace BlockWorld {
	class GameObject;
	class ObjectBehavior {
		protected:
			ObjectBehavior() { }
		
		public:
			virtual ~ObjectBehavior() { }
			virtual void perform(GameObject& object, unsigned int deltaTime) = 0;
	};
};

#endif // __BLOCKWORLD_OBJECTBEHAVIOR_H__
