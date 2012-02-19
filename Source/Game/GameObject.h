#ifndef __BLOCKWORLD_GAMEOBJECT_H__
#define __BLOCKWORLD_GAMEOBJECT_H__

#include "../Engine/Engine.h"
#include "../Engine/Position.h"

using namespace BadEngine;

namespace BlockWorld {
	class Camera;
	class ObjectBehavior;
	class World;
	class GameObject {
		protected:
			World* m_world;
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
		
		private:
			GameObject();
		
		public:
			GameObject(World& world);
			virtual ~GameObject();
			
			World* getWorld();
			
			double getX();
			double getY();
			double getVelocityX();
			double getVelocityY();
			int getSpriteWidth();
			int getSpriteHeight();
			
			bool isJumping();
			bool isTouchingGround();
			
			bool wantToMoveLeft();
			bool wantToMoveRight();
			bool wantToJump();
			
			void setX(double x);
			void setY(double y);
			void setVelocityX(double velocity);
			void setVelocityY(double velocity);
			void setMoveLeft(bool move);
			void setMoveRight(bool move);
			void setTouchingGround(bool touching);
			void setJump(bool jump);
			void setJumping(bool jumping);
			
			void update(unsigned int deltaTime);
			void draw(Engine& engine, Camera& camera);
	};
};

#endif // __BLOCKWORLD_GAMEOBJECT_H__
