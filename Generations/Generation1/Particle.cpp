/*
 * Particle.cpp
 *
 *  Created on: Jan 17, 2022
 *      Author: Patrick
 */

#include "Particle.h"


Particle::Particle():Particle(0,0,Color::White())
{
}

Particle::Particle(int x, int y, Color color)
{
	this->color = color;
	this->x= x;
	this->y= y;
	on = false;
}

void Particle::toggle()
{
	if(on)
	{
		on =false;
	}
	else
	{
		on = true;
	}
}

void Particle::oscillate()
{
	if(rUp && color.GetRed()+1 <255)
	{
		color.SetRed(color.GetRed()+1);
	}
	else if(color.GetRed()-1 < 0)
	{
		rUp = true;
	}
	else
	{
		color.SetRed(color.GetRed()-1);
		rUp = false;
	}

	if(gUp && color.GetGreen()+1 <255)
	{
		color.SetGreen(color.GetGreen()+1);
	}
	else if(color.GetGreen()-1 < 0)
	{
		gUp = true;
	}
	else
	{
		color.SetGreen(color.GetGreen()-1);
		gUp = false;
	}

	if(bUp && color.GetBlue()+1 <255)
	{
		color.SetBlue(color.GetBlue()+1);
	}
	else if(color.GetBlue()-1 < 0)
	{
		bUp = true;
	}
	else
	{
		color.SetBlue(color.GetBlue()-1);
		bUp = false;
	}

}

