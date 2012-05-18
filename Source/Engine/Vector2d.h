#ifndef __BADENGINE_VECTOR2D_H__
#define __BADENGINE_VECTOR2D_H__

namespace BadEngine {
	class Vector2d {
		private:
			double m_x;
			double m_y;
		
		public:
			Vector2d();
			Vector2d(double x, double y);
			~Vector2d();
			double getX();
			double getY();
			double length();
			void normalize();
			double angle(Vector2d& other);
	};
};

#endif // __BADENGINE_VECTOR2D_H__
