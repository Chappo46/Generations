/*
 * GameScene.cpp
 *
 *  Created on: Nov 26, 2021
 *      Author: patri
 */

#include <GenerationScene.h>

#include "../Generations/Generation.h"

GenerationScene::GenerationScene(std::unique_ptr<Generation> optrGame):mGeneration(std::move(optrGame))
{

}

void GenerationScene::Init()
{
	mGeneration->Init(mGameController);
}
void GenerationScene::Update(uint32_t dt)
{
	mGeneration->Update(dt);
}

void GenerationScene::Draw(Screen& screen)
{
	mGeneration->Draw(screen);
}

const std::string& GenerationScene::GetSceneName() const
{
	return mGeneration->GetName();
}



