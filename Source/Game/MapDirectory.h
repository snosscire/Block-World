#ifndef __BLOCKWORLD_MAPDIRECTORY_H__
#define __BLOCKWORLD_MAPDIRECTORY_H__

#include <string>

using namespace std;

namespace BlockWorld {
	class MapDirectory {
		private:
			string m_directoryName;
			string m_directoryPath;
			string m_imagePath;
			string m_xmlPath;
			string m_name;
			string m_description;
		
		private:
			MapDirectory();
		
		public:
			MapDirectory(string directoryPath, string directoryName, string imagePath);
			virtual ~MapDirectory();
			string& getImagePath();
			string& getXMLPath();
			string& getName();
			string& getDescription();
			void setXMLPath(string path);
			bool hasXML();
	};
};

#endif // __BLOCKWORLD_MAPDIRECTORY_H__
