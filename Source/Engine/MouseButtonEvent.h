#ifndef __MOUSEBUTTONEVENT_H__
#define __MOUSEBUTTONEVENT_H__

#include "MouseButton.h"

namespace BadEngine {
	class MouseButtonEvent {
		protected:
			MouseButtonEvent() { }
			~MouseButtonEvent() { }
		
		public:
			virtual unsigned int getX() = 0;
			virtual unsigned int getY() = 0;
			virtual MouseButton getButton() = 0;
	};
};

#endif // __MOUSEBUTTONEVENT_H__
