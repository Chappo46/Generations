/*
 * Shape.cpp
 *
 *  Created on: Nov 18, 2021
 *      Author: Patrick
 */

#include "Shape.h"

void Shape::MoveBy(const Vec2D& deltaOffset)
{
	for(Vec2D& point: mPoints)
	{
		point = point + deltaOffset;
	}
}

