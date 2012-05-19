#ifndef __BLOCKWORLD_CAMERA_H__
#define __BLOCKWORLD_CAMERA_H__

namespace BlockWorld {
	class Camera {
		protected:
			Camera() { }
		
		public:
			virtual ~Camera() { }
			virtual void update() { }
			virtual int getLeft() = 0;
			virtual int getRight() = 0;
			virtual int getTop() = 0;
			virtual int getBottom() = 0; 
	};
};

#endif // __BLOCKWORLD_CAMERA_H__
