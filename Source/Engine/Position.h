#ifndef __BADENGINE_POSITION_H__
#define __BADENGINE_POSITION_H__

namespace BadEngine {
	class Position {
		private:
			unsigned int m_x;
			unsigned int m_y;
		
		public:
			Position();
			Position(unsigned int x, unsigned int y);
			~Position();
			void setX(unsigned int x);
			void setY(unsigned int y);
			unsigned int getX();
			unsigned int getY();
	};
};

#endif // __BADENGINE_POSITION_H__
