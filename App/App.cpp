/*
 * App.cpp
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick
 */
#include "GenerationScene.h"
#include "Generation1.h"
#include "App.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "ArcadeScene.h"
#include <cassert>

App& App::Singleton()
{
	static App theApp;
	return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	mnoptrWindow = mScreen.Init(width, height, mag);

	std::unique_ptr<ArcadeScene> arcadeScene = std::make_unique<ArcadeScene>();

	PushScene(std::move(arcadeScene));

	{
		std::unique_ptr<Generation1> generation1 = std::make_unique<Generation1>();

		std::unique_ptr<GenerationScene> generation1Scene = std::make_unique<GenerationScene>(std::move(generation1));

		PushScene(std::move(generation1Scene));
	}
	return mnoptrWindow != nullptr;
}

/**
 * Runs the main loop for the game
 */
void App::Run()
{
	//if the window is initialized?
	if(mnoptrWindow)
	{
		//Create bool for game loop. Run until program exit.
		bool running = true;

		//SDL call to get accurate time to help correct the delta of the game engine.
		uint32_t lastTick = SDL_GetTicks();
		uint32_t currentTick = lastTick;

		//Delta Time
		uint32_t dt = 10;
		uint32_t accumulator = 0;

		/*
		 * Initializes the input controller.
		 * Sets the "quit" action of the input controller to set "running" to false.
		 */
		mInputController.Init([&running](uint32_t dt, InputState state){
			running = false;
		});


		//Loop runs indefinitely until program is exited
		while(running)
		{
			currentTick = SDL_GetTicks();
			uint32_t frameTime = currentTick - lastTick;

			if(frameTime > 300)
			{
				frameTime = 300;
			}

			lastTick = currentTick;

			accumulator +=frameTime;

			//Input
			mInputController.Update(dt);

			Scene* topScene = App::TopScene();
			assert(topScene && "Why don't we have a scene");

			if(topScene)
			{
				//Update
				while(accumulator >= dt)
				{
					//update current scene by dt
					topScene->Update(dt);
//					std::cout<<"Delta time step: " << dt << std::endl;
					accumulator -= dt;
				}
				//render
				topScene->Draw(mScreen);
			}
			mScreen.SwapScreens();
		}

	}

}


void App::PushScene(std::unique_ptr<Scene> scene)
{
	assert(scene && "Don't push null pointer");
	if(scene)
	{
		scene->Init();
		mInputController.SetGameController(scene->GetGameController());
		mSceneStack.emplace_back(std::move(scene));
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}
}

void App::PopScene()
{
	if(mSceneStack.size() > 1)
	{
		mSceneStack.pop_back();
	}

	if(TopScene())
	{
		mInputController.SetGameController(TopScene()->GetGameController());
		SDL_SetWindowTitle(mnoptrWindow, TopScene()->GetSceneName().c_str());
	}
}

Scene* App::TopScene()
{
	if(mSceneStack.empty())
	{
		return nullptr;
	}
	return mSceneStack.back().get();
}

const std::string& App::GetBasePath()
{
	static std::string basePath = SDL_GetBasePath();

	return basePath;
}
