/*
 * ColorOscillator.h
 *
 *  Created on: Nov 12, 2021
 *      Author: patri
 */

#ifndef MYEXPERIMENTS_COLOROSCILLATOR_H_
#define MYEXPERIMENTS_COLOROSCILLATOR_H_

#include "color.h"

class ColorOscillator
{
public:
	ColorOscillator();
	void oscillate(Color& color);
	void oscillate(Color& color, int speed);
private:
	bool rUp;
	bool gUp;
	bool bUp;
	int oscillateNumber(int toOsc,int speed, bool& up);
};



#endif /* MYEXPERIMENTS_COLOROSCILLATOR_H_ */
