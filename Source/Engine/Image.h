#ifndef __BADENGINE_IMAGE_H__
#define __BADENGINE_IMAGE_H__

namespace BadEngine {
	class Image {
		protected:
			Image() { }
		
		public:
			virtual ~Image() { }
			
			virtual void draw(int x, int y) = 0;
			virtual int getWidth() = 0;
			virtual int getHeight() = 0;
			virtual void flip() = 0;
	};
};

#endif // __BADENGINE_IMAGE_H__
