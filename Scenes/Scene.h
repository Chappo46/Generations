/*
 * Scene.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick Murphy
 *      Interface for a scene.
 *      Scenes are the views shown in the game. They each have there own GameController associated with them.
 *      Each Scene has the basic required program functionality of Updating and Drawing.
 */

#ifndef SHAPES_SCENE_H_
#define SHAPES_SCENE_H_

#include <string>
#include <stdint.h>
#include "GameController.h"

class Screen;

//Scene Interface
class Scene
{
public:
	virtual ~Scene() {}

	/**
	 * In the Scene's initialization, the controls are setup for the Scene.
	 */
	virtual void Init() = 0;

	/**
	 * Updates all elements of the scene.
	 */
	virtual void Update(uint32_t dt) = 0;

	/**
	 * Draws all elements of the scene.
	 */
	virtual void Draw(Screen& theScreen) = 0;

	/**
	 * Returns the name of the scene.
	 */
	virtual const std::string& GetSceneName() const = 0;
	GameController* GetGameController() {return &mGameController;}
protected:
	GameController mGameController;
};



#endif /* SHAPES_SCENE_H_ */
