/*
 * InputController.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick Murphy
 *      Gets buttons pressed from SDL and runs actions associated with them.
 */

#ifndef INPUT_INPUTCONTROLLER_H_
#define INPUT_INPUTCONTROLLER_H_

#include "InputAction.h"

class GameController;

class InputController
{
public:
	InputController();
	//Quit action must be initialized
	void Init(InputAction quitAction);

	/**
	 * Polls SDL for button inputs and calls the appropriate actions for the button presses.
	 */
	void Update(uint32_t dt);

	/**
	 * Sets the active GameController.
	 */
	void SetGameController(GameController* controllera);
private:
	InputAction mQuit;
	GameController* mnoptrCurrentController;
};



#endif /* INPUT_INPUTCONTROLLER_H_ */
