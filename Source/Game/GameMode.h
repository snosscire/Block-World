#ifndef __BADENGINE_GAMEMODE_H__
#define __BADENGINE_GAMEMODE_H__

namespace BadEngine {
	class Game;
	class GameMode {
		private:
			bool m_started;
		
		protected:
			Game* m_game;
			
		private:
			virtual void performStart() = 0;
			virtual void performStop() = 0;
			virtual void performUpdate() = 0;
			virtual void performDraw() = 0;
		
		protected:
			GameMode();
			GameMode(Game* game);
		
		public:
			~GameMode();
			void start();
			void stop();
			void update();
			void draw();
	};
};

#endif // __BADENGINE_GAMEMODE_H__
