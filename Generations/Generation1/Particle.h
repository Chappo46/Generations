/*
 * Particle.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Patrick
 */

#ifndef GENERATIONS_GENERATION1_PARTICLE_H_
#define GENERATIONS_GENERATION1_PARTICLE_H_

#include "Color.h"

class Particle
{
public:
	Particle();
	Particle(int x, int y, Color color);
	inline const int getX(){return x;}
	inline const int getY(){return y;}
	inline Color getColor(){return color;}
	inline void setColor(Color newColor){color = newColor;}
	inline bool isOn(){return on;}
	void oscillate();
	void toggle();
private:
	Color color;
	bool rUp = true;
	bool gUp = true;
	bool bUp = true;
	bool on;
	int x;
	int y;
};


#endif /* GENERATIONS_GENERATION1_PARTICLE_H_ */
