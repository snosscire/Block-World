#ifndef __BLOCKWORLD_OBJECTCONTROLLER_H__
#define __BLOCKWORLD_OBJECTCONTROLLER_H__

#include <iostream>

namespace BlockWorld {
	class GameObject;
	class ObjectController {
		protected:
			GameObject* m_object;
		
		protected:
			ObjectController() : m_object(NULL) { }
			ObjectController(GameObject* object) : m_object(object) { }
		
		public:
			virtual ~ObjectController() { }
	};
};

#endif // __BLOCKWORLD_OBJECTCONTROLLER_H__
