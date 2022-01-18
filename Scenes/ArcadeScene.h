/*
 * ArcadeScene.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Patrick
 */

#ifndef SCENES_ARCADESCENE_H_
#define SCENES_ARCADESCENE_H_

#include "Scene.h"
#include <memory>

enum eGame
{
	TETRIS = 0,
	BREAK_OUT,
	ASTEROIDS,
	PACMAN,
	NUM_GAMES
};

class ArcadeScene: public Scene
{
public:
	ArcadeScene();

	/**
	 * In the Scene's initialization, the controls are setup for the Scene.
	 */
	virtual void Init() override;

	/**
	 * Updates all elements of the scene.
	 */
	virtual void Update(uint32_t dt) override;

	/**
	 * Draws all elements of the scene.
	 */
	virtual void Draw(Screen& theScreen) override;

	virtual const std::string& GetSceneName() const override;
private:
	std::unique_ptr<Scene> GetScene(eGame game);
};



#endif /* SCENES_ARCADESCENE_H_ */
