/*
 * ColorOscillator.cpp
 *
 *  Created on: Nov 12, 2021
 *      Author: patri
 */
#include "ColorOscillator.h"


ColorOscillator::ColorOscillator():rUp{true},gUp{true},bUp{true}
{

}

void ColorOscillator::oscillate(Color& color)
{
	oscillate(color,1);
}
void ColorOscillator::oscillate(Color& color,int speed)
{
	color.SetRed(oscillateNumber(color.GetRed(),speed,rUp));
	color.SetGreen(oscillateNumber(color.GetGreen(),speed,gUp));
	color.SetBlue(oscillateNumber(color.GetBlue(),speed,bUp));
}

int ColorOscillator::oscillateNumber(int toOsc,int speed, bool& up)
{
			if(toOsc >= 255)
			{
				up =false;
			}
			else if(toOsc <=1)
			{
				up = true;
			}
			if(up)
			{
				toOsc+=speed;
			}
			else
			{
				toOsc-=speed;
			}
			return toOsc;
}
