all:
	g++-4.4 -g -Wall -c \
		-DAPHEX_AS_COMPONENT \
		Source/External/aphex/*.c \
		Source/External/tinyxml2/tinyxml2.cpp \
		Source/Engine/SDL/*.cpp \
		Source/Engine/*.cpp \
		Source/Game/Console/*.cpp \
		Source/Game/Network/*.cpp \
		Source/Game/Blocks/Default/*.cpp \
		Source/Game/Blocks/*.cpp \
		Source/Game/Objects/*.cpp \
		Source/Game/ObjectBehaviors/*.cpp \
		Source/Game/*.cpp \
		Source/main.cpp
	
	g++-4.4 *.o -o BlockWorld.x86_64 \
		`sdl-config --cflags --libs` -lSDL_image -lSDL_gfx -lenet

