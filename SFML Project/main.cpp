#include <iostream>

#include "ApplicationManager.h"
#include "ConfigurationManager.h"
#include "Components.h"

using namespace std;
using namespace Game;

int main()
{

	//Initialize Application
	ApplicationManager app;

	//Game Loops
	while (app.IsRunning())
	{
		app.CaptureInput();

		app.Update();
		app.LateUpdate();
		app.Draw();

		app.CalculateDeltaTime();
	}


	return EXIT_SUCCESS;
}