#ifndef __BADENGINE_RECTANGLE_H__
#define __BADENGINE_RECTANGLE_H__

#include "Position.h"

namespace BadEngine {
	class Rectangle {
		private:
			Position m_position;
			double m_width;
			double m_height;
		
		public:
			Rectangle();
			Rectangle(double x, double y, double width, double height);
			~Rectangle();
			void setX(double x);
			void setY(double y);
			void setWidth(double width);
			void setHeight(double height);
			double getX();
			double getY();
			double getWidth();
			double getHeight();
	};
};

#endif // __BADENGINE_RECTANGLE_H__