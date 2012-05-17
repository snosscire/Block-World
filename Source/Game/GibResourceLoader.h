#ifndef __BLOCKWORLD_GIBRESOURCELOADER_H__
#define __BLOCKWORLD_GIBRESOURCELOADER_H__

#include "../Engine/Engine.h"

#include <string>
#include <vector>

using namespace std;
using namespace BadEngine;

namespace BlockWorld {
	class GibResourceLoader {
		private:
			Engine* m_engine;
			vector<string> m_skulls;
			vector<string> m_gibs;
		
		private:
			GibResourceLoader();
		
		public:
			GibResourceLoader(Engine& engine);
			~GibResourceLoader();
			void loadFile(const char* path);
			const char* getRandomSkull();
			const char* getRandomGib();
	};
};

#endif
