#include "DrawHitBoxesCommand.h"

#include "../Config.h"

#include <iostream>

using namespace std;

namespace BlockWorld {
	DrawHitBoxesCommand::DrawHitBoxesCommand() :
		ConsoleCommand()
	{
	}
	
	void DrawHitBoxesCommand::invoke(vector<string>& parameters) {
		Config::DrawHitBoxes = !Config::DrawHitBoxes;
	}
};

