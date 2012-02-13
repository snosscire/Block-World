#ifndef __BADENGINE_OBJECTBEHAVIOR_H__
#define __BADENGINE_OBJECTBEHAVIOR_H__

namespace BadEngine {
	class GameObject;
	class ObjectBehavior {
		protected:
			ObjectBehavior() { }
		
		public:
			virtual ~ObjectBehavior() { }
			virtual void perform(GameObject& object, unsigned int deltaTime) = 0;
	};
};

#endif // __BADENGINE_OBJECTBEHAVIOR_H__
