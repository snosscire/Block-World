#ifndef __BADENGINE_GAMEOBJECT_H__
#define __BADENGINE_GAMEOBJECT_H__

namespace BadEngine {
	class Camera;
	class Engine;
	class ObjectBehavior;
	class Position;
	class GameObject {
		private:
			double m_x;
			double m_y;
			double m_velocityX;
			double m_velocityY;
			bool m_moveLeft;
			bool m_moveRight;
			bool m_jump;
			bool m_jumping;
			bool m_touchingGround;
			ObjectBehavior* m_movingBehavior;
			ObjectBehavior* m_jumpingBehavior;
			ObjectBehavior* m_fallingBehavior;
			ObjectBehavior* m_collidingBehavior;
		
		public:
			GameObject();
			virtual ~GameObject();
			
			double getX();
			double getY();
			double getVelocityX();
			double getVelocityY();
			unsigned int getSpriteWidth();
			unsigned int getSpriteHeight();
			
			void setX(double x);
			void setY(double y);
			void setVelocityX(double velocity);
			void setVelocityY(double velocity);
			void setMoveLeft(bool move);
			void setMoveRight(bool move);
			
			void update(unsigned int deltaTime);
			void draw(Engine& engine, Camera& camera);
	};
};

#endif // __BADENGINE_GAMEOBJECT_H__
