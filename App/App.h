/*
 * App.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick Murphy
 *      Based on tutorials from Learn to program by making games.
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "Screen.h"
#include "Scene.h"
#include <stdint.h>
#include <vector>
#include <memory>
#include "InputController.h"

struct SDL_Window;

class App
{
public:

	/**
	 * Returns a static instance of the app.
	 * Singleton to prevent a new instance of the app to be created.
	 */
	static App& Singleton();

	/**
	 * Initializes an app object.
	 * @param width
	 * @param height
	 * @param mag
	 * @return
	 */
	bool Init(uint32_t width, uint32_t height, uint32_t mag);

	/**
	 * Runs the main loop of the program. The main game loop.
	 * Rendering and updating the game at a stable frame rate.
	 */
	void Run();

	/**
	 * Returns the width of the screen.
	 * @return
	 */
	inline uint32_t Width() const {return mScreen.Width();}

	/**
	 * Returns the height of the screen.
	 * @return
	 */
	inline uint32_t Height() const {return mScreen.Height();}

	void PushScene(std::unique_ptr<Scene> scene);
	void PopScene();
	Scene* TopScene();

	static const std::string& GetBasePath();

private:
	Screen mScreen;
	SDL_Window* mnoptrWindow;

	//A vector being used as a stack to hold each "Scene" object.
	std::vector<std::unique_ptr<Scene>> mSceneStack;
	InputController mInputController;
};

#endif /* APP_APP_H_ */
