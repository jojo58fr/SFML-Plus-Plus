#include <iostream>

#include "DisplayManager.h"
#include "ConfigurationManager.h"
#include "Components.h"

using namespace std;
using namespace Game;

int main()
{
	//Intiialize Random Seed
	srand(static_cast<unsigned>(time(0)));

	//Initialize Application
	DisplayManager* app = new DisplayManager();
	//ConfigurationManager* file = new ConfigurationManager("C:\\Users\\Joach\\source\\repos\\SFML Project\\x64\\Debug\\settings.cfg");

	//Game Loops
	while (app->IsRunning())
	{
		app->update();
		app->render();
	}


	return EXIT_SUCCESS;
}