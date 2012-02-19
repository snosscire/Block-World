#ifndef __BADENGINE_EVENTOBSERVER_H__
#define __BADENGINE_EVENTOBSERVER_H__

#include "KeyboardButtonEvent.h"
#include "MouseMovementEvent.h"
#include "MouseButtonEvent.h"

namespace BadEngine {
	class EventObserver {
		protected:
			EventObserver() { }
			virtual ~EventObserver() { }
		
		public:
			virtual void onQuit() { }
			virtual void onKeyboardButtonDown(KeyboardButtonEvent& event) { }
			virtual void onKeyboardButtonUp(KeyboardButtonEvent& event) { }
			virtual void onMouseButtonDown(MouseButtonEvent& event) { }
			virtual void onMouseButtonUp(MouseButtonEvent& event) { }
			virtual void onMouseMovement(MouseMovementEvent& event) { }
	};
};

#endif // __BADENGINE_EVENTOBSERVER_H__
