/*
 * Generation1.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Patrick
 */

#ifndef GENERATIONS_GENERATION1_GENERATION1_H_
#define GENERATIONS_GENERATION1_GENERATION1_H_

#include "Generation.h"
#include "Color.h"
#include "Vec2D.h"
#include "Particle.h"
#include <vector>

enum G1_Mode
{
	DEFAULT = 0,
	ALL,
	FRAC,
	MELT,
	LINE,
	RIVER
};

class Generation1: public Generation
{
public:
	virtual void Init(GameController& controller) override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& screen) override;
	virtual const std::string& GetName() const override;
private:
	bool changeModes = false;
	int changeTime = 5000;
	G1_Mode mode = DEFAULT;
	std::vector<std::vector<Particle>> particles;
};



#endif /* GENERATIONS_GENERATION1_GENERATION1_H_ */
