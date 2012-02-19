#ifndef __BADENGINE_ENGINE_H__
#define __BADENGINE_ENGINE_H__

#include <map>
#include <list>

#include "EventType.h"
#include "EventObserver.h"

using namespace std;

namespace BadEngine {
	class Rectangle;
	class Engine {
		protected:
			map<EventType, list<EventObserver*> > m_eventObservers;
			Engine();
		
		public:
			~Engine();
			void registerEventObserver(EventType, EventObserver* observer);
			virtual void start() = 0;
			virtual void stop() = 0;
			virtual void notifyEventObservers() = 0;
			virtual void clearScreen() = 0;
			virtual void updateScreen() = 0;
			virtual void drawRectangle(Rectangle& rectangle, int red, int green, int blue) = 0;
			virtual int getRandomNumber(int min, int max) = 0;
			virtual int getScreenWidth() = 0;
			virtual int getScreenHeight() = 0;
			virtual double getCurrentTime() = 0;
	};
};

#endif // __BADENGINE_ENGINE_H__
