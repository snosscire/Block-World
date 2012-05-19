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
	class Weapon;
	class ObjectManager;
	class DamageHandler;
	class GameObject {
		protected:
			World* m_world;
			double m_x;
			double m_y;
			double m_screenX;
			double m_screenY;
			double m_velocityX;
			double m_velocityY;
			double m_angle;
			bool m_moveLeft;
			bool m_moveRight;
			bool m_jump;
			bool m_jumping;
			bool m_touchingGround;
			int m_health;
			ObjectBehavior* m_movingBehavior;
			ObjectBehavior* m_jumpingBehavior;
			ObjectBehavior* m_fallingBehavior;
			ObjectBehavior* m_collidingBehavior;
			ObjectController* m_controller;
			Sprite* m_sprite;
			list<Square*> m_collisionRectangles;
			double m_nextNetworkUpdate;
			int m_networkID;
			Weapon* m_weapon;
			ObjectManager* m_manager;
			bool m_canTakeDamage;
			DamageHandler* m_damageHandler;
		
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
			double getAngle();
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
			void setAngle(double angle);
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
			
			int getHealth();
			void setHealth(int health);
			bool takeDamage(int damage);
			bool isAlive();
			
			Weapon* getWeapon();
			void setWeapon(Weapon& weapon);
			
			void setManager(ObjectManager* manager);
			ObjectManager* getManager();
			
			void setCanTakeDamage(bool can);
			void setDamageHandler(DamageHandler* handler);
	};
};

#endif // __BLOCKWORLD_GAMEOBJECT_H__
