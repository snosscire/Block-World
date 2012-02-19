#ifndef __BADENGINE_POSITION_H__
#define __BADENGINE_POSITION_H__

namespace BadEngine {
	class Position {
		private:
			int m_x;
			int m_y;
		
		public:
			Position();
			Position(int x, int y);
			~Position();
			void setX(int x);
			void setY(int y);
			int getX();
			int getY();
	};
};

#endif // __BADENGINE_POSITION_H__
