/*
 * GameController.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick Murphy
 *      Defines InputKeys for a game and has methods to assign actions to them in a vector.
 *      Actions for the keys are defined in a particular scene.
 */

#ifndef INPUT_GAMECONTROLLER_H_
#define INPUT_GAMECONTROLLER_H_

#include "InputAction.h"
#include <vector>

class GameController
{
public:
	GameController();

	/**
	 * Returns the InputAction for a specified key.
	 */
	InputAction GetActionForKey(InputKey key);

	/**
	 * Adds a ButtonAction to this object.
	 */
	void AddInputActionForKey(const ButtonAction& buttonAction);

	/**
	 * Clears all of the ButtonActions associated with this object.
	 */
	void ClearAll();

	/**
	 * Returns true if a button is pressed.
	 */
	static bool IsPressed(InputState state);

	/**
	 * Returns true if a button is released.
	 */
	static bool IsReleased(InputState state);

	//Associate SDL Keys in the source file with InputKey names.
	static InputKey ActionKey();
	static InputKey SKey();
	static InputKey PauseKey();
	static InputKey CancelKey();
	static InputKey LeftKey();
	static InputKey RightKey();
	static InputKey UpKey();
	static InputKey DownKey();

	inline const MouseMovedAction GetMouseMovedAction() {return mMouseMovedAction; }
	inline void SetMouseMovedAction(const MouseMovedAction& mouseMovedAction){mMouseMovedAction = mouseMovedAction;}

	/**
	 * Loops through the mMouseButtonActions and returns the MouseInputAction for the given MouseButton.
	 */
	MouseInputAction GetMouseButtonActionForMouseButton(MouseButton button);
	void AddMouseButtonAction(const MouseButtonAction&  mouseButtonAction);

	//Associate SDL Buttons in the source file with MouseButton names.
	static MouseButton LeftMouseButton();
	static MouseButton RightMouseButton();

private:
	std::vector<ButtonAction> mButtonActions;
	std::vector<MouseButtonAction> mMouseButtonActions;
	MouseMovedAction mMouseMovedAction;

};



#endif /* INPUT_GAMECONTROLLER_H_ */
