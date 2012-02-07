#ifndef __BADENGINE_CAMERA_H__
#define __BADENGINE_CAMERA_H__

namespace BadEngine {
	class Camera {
		protected:
			Camera() { }
		
		public:
			~Camera() { }
			virtual void update() { }
			virtual unsigned int getLeft() = 0;
			virtual unsigned int getRight() = 0;
			virtual unsigned int getTop() = 0;
			virtual unsigned int getBottom() = 0; 
	};
};

#endif // __BADENGINE_CAMERA_H__
