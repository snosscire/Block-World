#include "Engine.h"
#include "EventObserver.h"

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
};