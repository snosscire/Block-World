#ifndef __BLOCKWORLD_GAMEOBJECT_H__
#define __BLOCKWORLD_GAMEOBJECT_H__

#include "../Engine/Engine.h"
#include "../Engine/Position.h"
#include "../Engine/Square.h"
#include "../Engine/Sprite.h"

#include <list>
#include <string>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class GameNetworkClient;
	class Camera;
	class ObjectBehavior;
	class ObjectController;
	class World;
	class GameObject {
		protected:
			World* m_world;
			double m_x;
			double m_y;
			double m_screenX;
			double m_screenY;
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
			ObjectController* m_controller;
			Sprite* m_sprite;
			list<Square*> m_collisionRectangles;
			double m_nextNetworkUpdate;
			int m_networkID;
		
		private:
			GameObject();
		
		public:
			GameObject(World& world);
			virtual ~GameObject();
			
			World* getWorld();
			
			int getNetworkID();
			
			double getX();
			double getY();
			double getWorldX();
			double getWorldY();
			double getScreenX();
			double getScreenY();
			double getVelocityX();
			double getVelocityY();
			int getSpriteWidth();
			int getSpriteHeight();
			
			bool isJumping();
			bool isTouchingGround();
			
			bool wantToMoveLeft();
			bool wantToMoveRight();
			bool wantToJump();
			
			void setController(ObjectController* controller);
			
			void setX(double x);
			void setY(double y);
			void setVelocityX(double velocity);
			void setVelocityY(double velocity);
			void setMoveLeft(bool move);
			void setMoveRight(bool move);
			void setTouchingGround(bool touching);
			void setJump(bool jump);
			void setJumping(bool jumping);
			
			void spriteUpdate(double currentTime, double deltaTime);
			
			void update(double currentTime, double deltaTime, GameNetworkClient* network);
			void draw(Engine& engine, Camera& camera);
			
			void clearCollisionRectangles();
			void addCollisionRectangle(Square* rectangle);
			list<Square*>& getCollisionRectangles();
			
			void setSpriteAnimation(const string& name);
			const string& getCurrentSpriteAnimation();
	};
};

#endif // __BLOCKWORLD_GAMEOBJECT_H__
