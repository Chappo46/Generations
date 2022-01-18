/*
 * Star.cpp
 *
 *  Created on: Nov 10, 2021
 *      Author: patri
 */

#include "Star.h"
#include "Line2D.h"
#include <cmath>


Star::Star():Star(1,Vec2D::Zero)
{
}

Star::Star(float scale): Star(scale,Vec2D::Zero)
{

}

Star::Star(float scale, Vec2D centerPoint): mScale{scale}, mMiddlePoint(centerPoint)
{


	mOuterPoint0 = calcStarPoint(centerPoint,0,0,1);
	mOuterPoint1 = calcStarPoint(centerPoint,1,0,1);
	mOuterPoint2 = calcStarPoint(centerPoint,2,0,1);
	mOuterPoint3 = calcStarPoint(centerPoint,3,0,1);
	mOuterPoint4 = calcStarPoint(centerPoint,4,0,1);

	mInnerPoint0 = calcStarPoint(centerPoint,0,0,innerDiv);
	mInnerPoint1 = calcStarPoint(centerPoint,1,0,innerDiv);
	mInnerPoint2 = calcStarPoint(centerPoint,2,0,innerDiv);
	mInnerPoint3 = calcStarPoint(centerPoint,3,0,innerDiv);
	mInnerPoint4 = calcStarPoint(centerPoint,4,0,innerDiv);

	mLine0 = Line2D(mOuterPoint0,mInnerPoint0);
	mLine1 = Line2D(mOuterPoint0,mInnerPoint1);
	mLine2 = Line2D(mOuterPoint1,mInnerPoint1);
	mLine3 = Line2D(mOuterPoint1,mInnerPoint2);
	mLine4 = Line2D(mOuterPoint2,mInnerPoint3);
	mLine5 = Line2D(mOuterPoint2,mInnerPoint2);
	mLine6 = Line2D(mOuterPoint3,mInnerPoint4);
	mLine7 = Line2D(mOuterPoint3,mInnerPoint3);
	mLine8 = Line2D(mOuterPoint4,mInnerPoint0);
	mLine9 = Line2D(mOuterPoint4,mInnerPoint4);

}



const Vec2D Star::calcStarPoint(const Vec2D& center, int pointNumber, int rotation, float division)
{
	int angle;
	if(division>1)
	{
		angle = 18;
	}
	else
	{
		angle = 54;
	}
	float x = cos((angle+(72*pointNumber)+rotation)*(3.14159265/180))*(mScale/division);
	float y = sin((angle+(72*pointNumber)+rotation)*(3.14159265/180))*(mScale/division);

	Vec2D newPoint(x+center.GetX(),y+center.GetY());

	return newPoint;

}

void Star::Rotate(int degrees)
{

	mOuterPoint0 = calcStarPoint(mMiddlePoint,0,degrees,1);
	mOuterPoint1 = calcStarPoint(mMiddlePoint,1,degrees,1);
	mOuterPoint2 = calcStarPoint(mMiddlePoint,2,degrees,1);
	mOuterPoint3 = calcStarPoint(mMiddlePoint,3,degrees,1);
	mOuterPoint4 = calcStarPoint(mMiddlePoint,4,degrees,1);

	mInnerPoint0 = calcStarPoint(mMiddlePoint,0,degrees,innerDiv);
	mInnerPoint1 = calcStarPoint(mMiddlePoint,1,degrees,innerDiv);
	mInnerPoint2 = calcStarPoint(mMiddlePoint,2,degrees,innerDiv);
	mInnerPoint3 = calcStarPoint(mMiddlePoint,3,degrees,innerDiv);
	mInnerPoint4 = calcStarPoint(mMiddlePoint,4,degrees,innerDiv);

	mLine0.SetP0(mOuterPoint0);
	mLine0.SetP1(mInnerPoint0);
	mLine1.SetP0(mOuterPoint0);
	mLine1.SetP1(mInnerPoint1);

	mLine2.SetP0(mOuterPoint1);
	mLine2.SetP1(mInnerPoint1);
	mLine3.SetP0(mOuterPoint1);
	mLine3.SetP1(mInnerPoint2);

	mLine4.SetP0(mOuterPoint2);
	mLine4.SetP1(mInnerPoint2);
	mLine5.SetP0(mOuterPoint2);
	mLine5.SetP1(mInnerPoint3);

	mLine6.SetP0(mOuterPoint3);
	mLine6.SetP1(mInnerPoint3);
	mLine7.SetP0(mOuterPoint3);
	mLine7.SetP1(mInnerPoint4);

	mLine8.SetP0(mOuterPoint4);
	mLine8.SetP1(mInnerPoint4);
	mLine9.SetP0(mOuterPoint4);
	mLine9.SetP1(mInnerPoint0);

}
