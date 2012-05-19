#ifndef __BLOCKWORLD_UPDATEMESSAGE_H__
#define __BLOCKWORLD_UPDATEMESSAGE_H__

#include "NetworkMessage.h"

#include <string>

using namespace std;

namespace BlockWorld {
	class UpdateMessage : public NetworkMessage {
		private:
			int m_id;
			double m_x;
			double m_y;
			double m_angle;
			double m_velocityX;
			double m_velocityY;
			int m_moveLeft;
			int m_moveRight;
			int m_jump;
			int m_jumping;
			int m_touchingGround;
			string m_currentAnimation;
		
		public:
			UpdateMessage();
			UpdateMessage(int id, double x, double y);
			UpdateMessage(int id, double x, double y, double angle, double velocityX, double velocityY, bool jumping, bool touchingGround);
			UpdateMessage(int id, double x, double y, bool moveLeft, bool moveRight, bool jump, bool touchingGround, string animation);
			UpdateMessage(string& data);
			virtual ~UpdateMessage();
			int getID();
			double getX();
			double getY();
			double getAngle();
			double getVelocityX();
			double getVelocityY();
			bool getMoveLeft();
			bool getMoveRight();
			bool getJump();
			bool getJumping();
			bool getTouchingGround();
			const string& getCurrentAnimation();
			string toData();
	};
};

#endif
