#ifndef __BADENGINE_ENGINE_H__
#define __BADENGINE_ENGINE_H__

#include <string>
#include <map>
#include <list>

#include "EventType.h"
#include "EventObserver.h"

using namespace std;

namespace BadEngine {
	class Rectangle;
	class Image;
	class Engine {
		protected:
			map<EventType, list<EventObserver*> > m_eventObservers;
			Engine();
		
		public:
			virtual ~Engine();
			void registerEventObserver(EventType, EventObserver* observer);
			virtual void start() = 0;
			virtual void stop() = 0;
			virtual void setVideoMode(int width, int height) = 0;
			virtual void notifyEventObservers() = 0;
			virtual void clearScreen() = 0;
			virtual void updateScreen() = 0;
			virtual void drawRectangle(Rectangle& rectangle, int red, int green, int blue) = 0;
			virtual int getRandomNumber(int min, int max) = 0;
			virtual int getScreenWidth() = 0;
			virtual int getScreenHeight() = 0;
			virtual double getCurrentTime() = 0;
			virtual Image* loadImage(string filename) = 0;
			virtual void grabInput() = 0;
			virtual void releaseInput() = 0;
	};
};

#endif // __BADENGINE_ENGINE_H__
