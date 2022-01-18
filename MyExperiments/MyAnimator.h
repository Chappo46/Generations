/*
 * MyAnimator.h
 *
 *  Created on: Nov 12, 2021
 *      Author: patri
 */

#ifndef MYEXPERIMENTS_MYANIMATOR_H_
#define MYEXPERIMENTS_MYANIMATOR_H_

#include "Screen.h"
#include "Star.h"
#include "Vec2D.h"
#include "ColorOscillator.h"

class MyAnimator
{
public:
	MyAnimator();
	void animate(Screen& screen);
private:
	int rotationDegrees{1};
	int counter2{1};
	int counter3{1};
	bool up = true;

	Star star ={50,Vec2D(640/2,360/2)};
	Color color;
	ColorOscillator colorOscillator;
};



#endif /* MYEXPERIMENTS_MYANIMATOR_H_ */
