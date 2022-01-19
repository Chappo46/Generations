/*
 * Generation1.cpp
 *
 *  Created on: Jan 17, 2022
 *      Author: Patrick
 */
#include "Generation1.h"
#include "Screen.h"
#include "stdlib.h"

int counter = 0;

void Generation1::Init(GameController& controller)
{
	for(int i = 0; i<360;i++)
	{
		std::vector<Particle> tempVec;
		for(int j = 0; j<640;j++)
		{
			tempVec.push_back(Particle(j,i,Color::Green()));
//			tempVec.push_back(Particle(j,i,Color(rand()%255,rand()%255,rand()%255,255)));
		}
		particles.push_back(tempVec);
	}

	mode = DEFAULT;
//	changeModes = true;

	if(mode == FRAC)
	{
		int y = rand() % 360;
		int x = rand() % 640;
		particles[y][x].toggle();
	}
}

void Generation1::Update(uint32_t dt)
{
//	for(int i = 0; i<1;i++)
//	{
	if(mode != FRAC)
	{
		int y = rand() % 360;
		int x = rand() % 640;
//		Color c = Color(rand()%255,rand()%255,rand()%255,255);
//		particles[y][x].setColor(c);
		particles[y][x].toggle();
	}

	if(counter % 7 ==0)
	{
		for(int i = 0; i<360;i++)
		{
			for(int j = 0; j<640;j++)
			{
				if(particles[i][j].isOn())
				{
					if(j+1<640)
					{
						if(mode == ALL)
						{
							if(i+1<360)
							{
								particles[i+1][j+1].toggle();
								if(particles[i+1][j+1].isOn()) particles[i+1][j+1].setColor(particles[i][j].getColor());
							}
						}
						if(mode == ALL)
						{
							if(i-1>=0)
							{
								particles[i-1][j+1].toggle();
								if(particles[i-1][j+1].isOn()) particles[i-1][j+1].setColor(particles[i][j].getColor());
							}

						}
						if(mode == DEFAULT || ALL || FRAC||LINE)
						{
							particles[i][j+1].toggle();
							if(mode != LINE)if(particles[i][j+1].isOn()) particles[i][j+1].setColor(particles[i][j].getColor());
						}
					}
					if(j-1>0)
					{
						if(mode == ALL)
						{
							if(i+1<360)
							{
								particles[i+1][j-1].toggle();
								if(particles[i+1][j-1].isOn()) particles[i+1][j-1].setColor(particles[i][j].getColor());
							}
						}

						if(mode == ALL)
						{
							if(i-1>=0)
							{
								particles[i-1][j-1].toggle();
								if(particles[i-1][j-1].isOn()) particles[i-1][j-1].setColor(particles[i][j].getColor());
							}
						}

						if(mode == DEFAULT || ALL|| FRAC||LINE)
						{
							particles[i][j-1].toggle();
							if(mode != LINE)if(particles[i][j-1].isOn())particles[i][j-1].setColor(particles[i][j].getColor());

						}
					}
					if(mode == DEFAULT || ALL|| FRAC)
					{
						if(i+1<360)
						{
							particles[i+1][j].toggle();
							if(particles[i+1][j].isOn()) particles[i+1][j].setColor(particles[i][j].getColor());
						}
						if(i-1>=0)
						{
							particles[i-1][j].toggle();
							if(particles[i-1][j].isOn())particles[i-1][j].setColor(particles[i][j].getColor());
						}
					}
				}
				particles[i][j].oscillate();
			}
		}
	}

	counter++;
	if(counter > changeTime && changeModes )
	{
		mode = static_cast<G1_Mode>(rand()%5);
		changeTime = rand()%10000;
		counter = 0;
	}

}

void Generation1::Draw(Screen& screen)
{
	for(int i = 0; i<360;i++)
	{
		for(int j = 0; j<640;j++)
		{
			screen.Draw(particles[i][j].getX(),particles[i][j].getY(),particles[i][j].getColor());
		}
	}
}

const std::string& Generation1::GetName() const
{
	static std::string name = "Generation 1";
	return name;
}




