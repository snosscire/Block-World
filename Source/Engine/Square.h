#ifndef __BADENGINE_SQUARE_H__
#define __BADENGINE_SQUARE_H__

#include "Position.h"

namespace BadEngine {
	class Square {
		private:
			Position m_position;
			double m_width;
			double m_height;
		
		public:
			Square();
			Square(double x, double y, double width, double height);
			~Square();
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

#endif // __BADENGINE_SQUARE_H__