#ifndef __BADENGINE_VIDEORESIZEEVENT_H__
#define __BADENGINE_VIDEORESIZEEVENT_H__

namespace BadEngine {
	class VideoResizeEvent {
		protected:
			VideoResizeEvent() { }
			~VideoResizeEvent() { }
		
		public:
			virtual int getWidth() = 0;
			virtual int getHeight() = 0;
	};
};

#endif // __BADENGINE_VIDEORESIZEEVENT_H__
