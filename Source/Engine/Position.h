#ifndef __BADENGINE_POSITION_H__
#define __BADENGINE_POSITION_H__

namespace BadEngine {
	class Position {
		private:
			double m_x;
			double m_y;
		
		public:
			Position();
			Position(double x, double y);
			~Position();
			void setX(double x);
			void setY(double y);
			double getX();
			double getY();
	};
};

#endif // __BADENGINE_POSITION_H__
