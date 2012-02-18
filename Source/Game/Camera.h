#ifndef __BLOCKWORLD_CAMERA_H__
#define __BLOCKWORLD_CAMERA_H__

namespace BlockWorld {
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

#endif // __BLOCKWORLD_CAMERA_H__
