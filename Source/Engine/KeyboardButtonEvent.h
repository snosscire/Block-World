#ifndef __BADENGINE_KEYBOARDBUTTONEVENT_H__
#define __BADENGINE_KEYBOARDBUTTONEVENT_H__

#include "KeyboardButton.h"

namespace BadEngine {
	class KeyboardButtonEvent {
		protected:
			KeyboardButtonEvent() { }
			~KeyboardButtonEvent() { }
		
		public:
			virtual KeyboardButton getButton() = 0;
	};
};

#endif // __BADENGINE_KEYBOARDBUTTONEVENT_H__
