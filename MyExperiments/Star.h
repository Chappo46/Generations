/*
 * Star.h
 *
 *  Created on: Nov 10, 2021
 *      Author: Patrick
 */

#ifndef MYEXPERIMENTS_STAR_H_
#define MYEXPERIMENTS_STAR_H_

#include "Vec2D.h"
#include "Line2D.h"

class Star
{
public:
	Star();
	Star(float scale);
	Star(float scale, Vec2D centerPoint);

	inline const Line2D& GetLine0() const {return mLine0;}
	inline const Line2D& GetLine1() const {return mLine1;}
	inline const Line2D& GetLine2() const {return mLine2;}
	inline const Line2D& GetLine3() const {return mLine3;}
	inline const Line2D& GetLine4() const {return mLine4;}
	inline const Line2D& GetLine5() const {return mLine5;}
	inline const Line2D& GetLine6() const {return mLine6;}
	inline const Line2D& GetLine7() const {return mLine7;}
	inline const Line2D& GetLine8() const {return mLine8;}
	inline const Line2D& GetLine9() const {return mLine9;}

	inline const Vec2D& GetOuterPoint0() const {return mOuterPoint0;}
	inline const Vec2D& GetOuterPoint1() const {return mOuterPoint1;}
	inline const Vec2D& GetOuterPoint2() const {return mOuterPoint2;}
	inline const Vec2D& GetOuterPoint3() const {return mOuterPoint3;}
	inline const Vec2D& GetOuterPoint4() const {return mOuterPoint4;}


	inline const Vec2D& GetInnerPoint0() const {return mInnerPoint0;}
	inline const Vec2D& GetInnerPoint1() const {return mInnerPoint1;}
	inline const Vec2D& GetInnerPoint2() const {return mInnerPoint2;}
	inline const Vec2D& GetInnerPoint3() const {return mInnerPoint3;}
	inline const Vec2D& GetInnerPoint4() const {return mInnerPoint4;}

	inline void SetScale(const int& scale) {mScale = scale;}
	void Rotate(int degrees);

private:

//	int rotationDegrees;
	const float innerDiv= 2.62f;
	float mScale;


	Vec2D mMiddlePoint;

	Vec2D mOuterPoint0;
	Vec2D mOuterPoint1;
	Vec2D mOuterPoint2;
	Vec2D mOuterPoint3;
	Vec2D mOuterPoint4;

	Vec2D mInnerPoint0;
	Vec2D mInnerPoint1;
	Vec2D mInnerPoint2;
	Vec2D mInnerPoint3;
	Vec2D mInnerPoint4;

	Line2D mLine0;
	Line2D mLine1;
	Line2D mLine2;
	Line2D mLine3;
	Line2D mLine4;
	Line2D mLine5;
	Line2D mLine6;
	Line2D mLine7;
	Line2D mLine8;
	Line2D mLine9;

	const Vec2D calcStarPoint(const Vec2D& center, int pointNumber, int rotation, float division);
};



#endif /* MYEXPERIMENTS_STAR_H_ */
