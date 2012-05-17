#ifndef __BLOCKWORLD_CONFIG_H__
#define __BLOCKWORLD_CONFIG_H__

#include <string>

using namespace std;

namespace BlockWorld {
	class Config {
		public:
			static void loadFile(const string& path);
			
			static double DefaultGravity;
			
			static double PlayerMoveSpeed;
			static double PlayerJumpSpeed;
			
			static double MaxCrosshairDistance;
			
			/* Gibs and Blood */
			static unsigned int MaxGibsOnScreen;
			static int SkullSpawnChance;
			static int GibsMin;
			static int GibsMax;
			static int BloodParticles;
			static int BloodParticlesSpread;
			static int GibMaxSpeedX;
			static int GibMaxSpeedY;
			static int BloodMaxSpeedX;
			static int BloodMaxSpeedY;
			
			static bool DrawHitBoxes;
	};
};

/*
	<config name="DefaultGravity" value="4.0" />
	
	<config name="PlayerMoveSpeed" value="2.0" />
	<config name="PlayerJumpSpeed" value="8.0" />
	
	<config name="MaxCrosshairDistance" value="180.0" />
	
	<!-- Gibs and Blood -->
	<config name="MaxGibs" value="500" />
	<config name="BloodParticles" value="50" />
	<config name="BloodParticlesSpread" value="6" />
	<config name="GibMaxSpeedX" value="8" />
	<config name="GibMaxSpeedY" value="8" />
	<config name="BloodMaxSpeedX" value="4" />
	<config name="BloodMaxSpeedY" value="4" />
*/

#endif // __BLOCKWORLD_CONFIG_H__
