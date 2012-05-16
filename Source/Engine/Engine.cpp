#include "Engine.h"
#include "EventObserver.h"
#include "Network.h"

namespace BadEngine {
	Engine::Engine() :
		m_eventObservers()
	{
	}
	
	Engine::~Engine()
	{
	}
	
	void Engine::registerEventObserver(EventType type, EventObserver* observer)
	{
		m_eventObservers[type].push_back(observer);
	}

	void Engine::unregisterEventObserver(EventType type, EventObserver* observer)
	{
		bool found = false;
		list<EventObserver*>::iterator it = m_eventObservers[type].begin();
		for ( ; it != m_eventObservers[type].end(); it++) {
			if ((*it) == observer) {
				found = true;
				break;
			}
		}
		if (found) {
			m_eventObservers[type].erase(it);
		}
	}
};

