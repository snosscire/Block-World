#ifndef __BADENGINE_MOUSEMOVEMENTEVENT_H__
#define __BADENGINE_MOUSEMOVEMENTEVENT_H__

namespace BadEngine {
	class MouseMovementEvent {
		protected:
			MouseMovementEvent() { }
			~MouseMovementEvent() { }
		
		public:
			virtual unsigned int getX() = 0;
			virtual unsigned int getY() = 0;
			virtual int getRelativeX() = 0;
			virtual int getRelativeY() = 0;
	};
};

#endif // __BADENGINE_MOUSEMOVEMENTEVENT_H__
