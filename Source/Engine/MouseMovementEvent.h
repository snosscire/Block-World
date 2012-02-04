#ifndef __MOUSEMOVEMENTEVENT_H__
#define __MOUSEMOVEMENTEVENT_H__

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

#endif // __MOUSEMOVEMENTEVENT_H__
