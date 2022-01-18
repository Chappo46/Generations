/*
 * MyAnimator.cpp
 *
*  Created on: Nov 12, 2021
 *      Author: patri
 */

#include "MyAnimator.h"

MyAnimator::MyAnimator()
{
	color.SetRed(0);
	color.SetGreen(100);
	color.SetBlue(200);
}


void MyAnimator::animate(Screen& screen)
{
//		if(counter2 % 20000 == 0)
//		{
			if(counter3 >=70)
			{
				up =false;
			}
			else if(counter3 <=1)
			{
				up = true;
			}
			if(up)
			{
				counter3++;
			}
			else
			{
				counter3--;
			}


			rotationDegrees++;
			star.Rotate(rotationDegrees);
			screen.Draw(star.GetLine0(), color);
			screen.Draw(star.GetLine1(), color);
			screen.Draw(star.GetLine2(), color);
			screen.Draw(star.GetLine3(), color);
			screen.Draw(star.GetLine4(), color);
			screen.Draw(star.GetLine5(), color);
			screen.Draw(star.GetLine6(), color);
			screen.Draw(star.GetLine7(), color);
			screen.Draw(star.GetLine8(), color);
			screen.Draw(star.GetLine9(), color);

			colorOscillator.oscillate(color);
			star.SetScale(counter3);
//			screen.SwapScreen();
//		}
//		counter2++;
}

