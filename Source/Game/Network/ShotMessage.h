#ifndef __BLOCKWORLD_SHOTMESSAGE_H__
#define __BLOCKWORLD_SHOTMESSAGE_H__

#include "NetworkMessage.h"

namespace BlockWorld {
	class ShotMessage : public NetworkMessage {
		private:
			int m_id;
			int m_weapon;
			double m_x;
			double m_y;
			double m_angle;
		
		public:
			ShotMessage();
			ShotMessage(int id, int weapon, double x, double y, double angle);
			ShotMessage(string& data);
			virtual ~ShotMessage();
			int getID();
			int getWeapon();
			double getX();
			double getY();
			double getAngle();
			string toData();
	};
};

#endif
