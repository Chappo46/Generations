/*
 * Shape.h
 *
 *  Created on: Nov 18, 2021
 *      Author: Patrick Murphy
 *      Defines an abstract interface for a Shape object.
 */

#ifndef SHAPES_SHAPE_H_
#define SHAPES_SHAPE_H_

#include "Vec2D.h"
#include <vector>

class Shape
{
public:
	virtual Vec2D GetCenterPoint() const = 0;
	virtual ~Shape(){}
	inline virtual std::vector<Vec2D> GetPoints() const {return mPoints;}
	void MoveBy(const Vec2D& deltaOffset);
protected:
	std::vector<Vec2D> mPoints;
};




#endif /* SHAPES_SHAPE_H_ */
