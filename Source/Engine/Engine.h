#ifndef __BADENGINE_ENGINE_H__
#define __BADENGINE_ENGINE_H__

#include <map>
#include <list>

#include "EventType.h"
#include "EventObserver.h"

using namespace std;

namespace BadEngine {
	class Engine {
		protected:
			map<EventType, list<EventObserver*> > m_eventObservers;
			Engine();
		
		public:
			~Engine();
			virtual void start() = 0;
			virtual void stop() = 0;
			void registerEventObserver(EventType, EventObserver* observer);
			virtual void notifyEventObservers() = 0;
			virtual void clearScreen() = 0;
			virtual void updateScreen() = 0;
	};
};

#endif // __BADENGINE_ENGINE_H__
