/*
 * GameScene.h
 *
 *  Created on: Nov 26, 2021
 *      Author: GameScenes load a Game object that will actually handle all of the actions for each method. This allows for different games to be loaded with one GameScene class.
 */

#ifndef SCENES_GENERATIONSCENE_H_
#define SCENES_GENERATIONSCENE_H_

#include "Scene.h"
#include <memory>
#include "../Generations/Generation.h"

class GenerationScene: public Scene
{
public:
	/*
	 * GameScene must be initialized with a Game object.
	 */
	GenerationScene(std::unique_ptr<Generation> optrGame);

	virtual ~GenerationScene(){}

	/**
	 * In the Scene's initialization, the controls are setup for the Scene.
	 * Handed to the Game object.
	 */
	virtual void Init() override;

	/**
	 * Updates all elements of the scene.
	 * Handed to the Game object.
	 */
	virtual void Update(uint32_t dt) override;

	/**
	 * Draws all elements of the scene.
	 * Handed to the Game object.
	 */
	virtual void Draw(Screen& screen) override;

	virtual const std::string& GetSceneName() const override;

private:
	std::unique_ptr<Generation> mGeneration;
};



#endif /* SCENES_GENERATIONSCENE_H_ */
