#ifndef __BADENGINE_RECTANGLE_H__
#define __BADENGINE_RECTANGLE_H__

#include "Position.h"

namespace BadEngine {
	class Rectangle {
		private:
			Position m_position;
			unsigned int m_width;
			unsigned int m_height;
		
		public:
			Rectangle();
			Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
			~Rectangle();
			unsigned int getX();
			unsigned int getY();
			unsigned int getWidth();
			unsigned int getHeight();
	};
};

#endif // __BADENGINE_RECTANGLE_H__