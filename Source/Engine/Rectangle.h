#ifndef __BADENGINE_RECTANGLE_H__
#define __BADENGINE_RECTANGLE_H__

#include "Position.h"

namespace BadEngine {
	class Rectangle {
		private:
			Position m_position;
			int m_width;
			int m_height;
		
		public:
			Rectangle();
			Rectangle(int x, int y, int width, int height);
			~Rectangle();
			void setX(int x);
			void setY(int y);
			void setWidth(int width);
			void setHeight(int height);
			int getX();
			int getY();
			int getWidth();
			int getHeight();
	};
};

#endif // __BADENGINE_RECTANGLE_H__