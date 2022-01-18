//============================================================================
// Name        : sdl_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#define SDL_MAIN_uHANDLED
#include <iostream>
#include "App.h"

using namespace std;

//Variables for screen height and width
const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int MY_SCREEN_WIDTH = 640;
const int MY_SCREEN_HEIGHT = 360;
const int MAGNIFICATION = 3;


int main(int argc, char *argv[])
{
	if(App::Singleton().Init(MY_SCREEN_WIDTH,MY_SCREEN_HEIGHT, MAGNIFICATION))
	{
		App::Singleton().Run();
	}
	else
	{
		std::cout<<"Failed to start singleton"<<std::endl;//TODO remove
	}

	return 0;
}

