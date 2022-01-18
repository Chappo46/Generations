/*
 * Generation.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Patrick
 */

#ifndef GENERATIONS_GENERATION_H_
#define GENERATIONS_GENERATION_H_


#include <string>
#include <stdint.h>

class GameController;
class Screen;

class Generation
{
public:
	/**
	 * Virtual Constructor for Game objects
	 */
	virtual~Generation(){}
	virtual void Init(GameController& controller) = 0;
	virtual void Update(uint32_t dt) = 0;
	virtual void Draw(Screen& screen) =0;
	virtual const std::string& GetName() const = 0;
};


#endif /* GENERATIONS_GENERATION_H_ */
