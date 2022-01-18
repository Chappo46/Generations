/*
 * InputAction.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick Murphy
 *      Creating type definitions for making input keys and actions. Using lambdas and abstract functions?
 */

#ifndef INPUT_INPUTACTION_H_
#define INPUT_INPUTACTION_H_

#include <functional>
#include <stdint.h>

// The "using" keyword used to abstract type definitions.
using InputKey = uint8_t;
using InputState = uint8_t;
using MouseButton = uint8_t;

//The "using" keyword to abstract function definitions??
using InputAction = std::function<void(uint32_t dt, InputState)>;

/**
 * Object that associates an InputKey(SDL key) with an InputAction(lambda.)
 */
struct ButtonAction
{
	InputKey key;
	InputAction action;
};

/**
 * Object to keep track of the mouse position in terms of x and y.
 */
struct MousePosition
{
	int32_t xPos, yPos;
};

//The "using" keyword to abstract function definitions??
using MouseMovedAction = std::function<void(const MousePosition& mousePosition)>;
using MouseInputAction = std::function<void(InputState state, const MousePosition& position)>;

/**
 * Object that associates an MouseButton(SDL) with an MouseInputAction(lambda.)
 */
struct MouseButtonAction
{
	MouseButton mouseButton;
	MouseInputAction mouseInputAction;
};

#endif /* INPUT_INPUTACTION_H_ */
