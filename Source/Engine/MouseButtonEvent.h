#ifndef __BADENGINE_MOUSEBUTTONEVENT_H__
#define __BADENGINE_MOUSEBUTTONEVENT_H__

#include "MouseButton.h"

namespace BadEngine {
	class MouseButtonEvent {
		protected:
			MouseButtonEvent() { }
			~MouseButtonEvent() { }
		
		public:
			virtual int getX() = 0;
			virtual int getY() = 0;
			virtual MouseButton getButton() = 0;
	};
};

#endif // __BADENGINE_MOUSEBUTTONEVENT_H__
