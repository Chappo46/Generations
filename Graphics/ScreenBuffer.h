/*
 * ScreenBuffer.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Patrick Murphy
 *      This class is used as an abstraction for an SDL surface. It is the surface that is drawn onto.
 */

#ifndef GRAPHICS_SCREENBUFFER_H_
#define GRAPHICS_SCREENBUFFER_H_

#include "Color.h"
struct SDL_Surface;

class ScreenBuffer
{
public:
	ScreenBuffer();
	ScreenBuffer(const ScreenBuffer& screenBuffer);
	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

	/**
	 * Initializes the surface with a specified SDL pixel format, width and height.
	 */
	void Init(uint32_t format, uint32_t width, uint32_t height);

	inline SDL_Surface * GetSurface() {return mSurface;}

	/**
	 * Clears the surface to a solid color.
	 */
	void Clear(const Color& c = Color::Black());

	/**
	 * Sets a pixel on the surface to a specific color at specific coordinates.
	 */
	void SetPixel(const Color& color, int x, int y);

private:
	SDL_Surface * mSurface;
	uint32_t GetIndex(int r, int c);
};

#endif /* GRAPHICS_SCREENBUFFER_H_ */
