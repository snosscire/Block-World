#ifndef __BLOCKWORLD_GAMEMODE_H__
#define __BLOCKWORLD_GAMEMODE_H__

namespace BlockWorld {
	class Game;
	class GameMode {
		private:
			bool m_started;
		
		protected:
			Game* m_game;
			
		private:
			virtual void performStart() = 0;
			virtual void performStop() = 0;
			virtual void performUpdate(double currentTime, double deltaTime) = 0;
			virtual void performDraw() = 0;
		
		protected:
			GameMode();
			GameMode(Game* game);
		
		public:
			~GameMode();
			void start();
			void stop();
			void update(double currentTime, double deltaTime);
			void draw();
	};
};

#endif // __BLOCKWORLD_GAMEMODE_H__
