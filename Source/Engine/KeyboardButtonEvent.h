#ifndef __KEYBOARDBUTTONEVENT_H__
#define __KEYBOARDBUTTONEVENT_H__

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

#endif // __KEYBOARDBUTTONEVENT_H__
