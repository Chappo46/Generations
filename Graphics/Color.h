/*
 * Color.h
 *
 *  Created on: Sep 15, 2021
 *      Author: patri
 *      Color class defines a way to work with color in SDL independent of the systems pixel format.
 *      Has a set of statically available colors.
 */

#ifndef GRAPHICS_COLOR_H_
#define GRAPHICS_COLOR_H_

#include <stdint.h>

//TODO: Learn about forward declaration.
struct SDL_PixelFormat;

/**
 * Color Class
 * To help define colors in a generalized pixel format.
 */
class Color
{
	//integer representation of color
	uint32_t mColor;
public:

	//Needs an SDL pixel format to be set before it will work...
	static const SDL_PixelFormat* mFormat;
	/**
	 * Initializes the color SDL_Color format being used. Must be set before the color class will work
	 */
	static void InitColorFormat(const SDL_PixelFormat * format);

	static Color Evaluate1MinusSourceAlpha(const Color& source, const Color& destination);

	//Statically available named color objects.
	static Color Black(){return Color(0,0,0,255);}
	static Color White(){return Color(255,255,255,255);}
	static Color Blue(){return Color(0,0,255,255);}
	static Color Red(){return Color(255,0,0,255);}
	static Color Green(){return Color(0,230,64,255);}
	static Color Yellow(){return Color(255,255,0,255);}
	static Color Magenta(){return Color(139,0,139,255);}
	static Color Cyan(){return Color(20,205,200,255);}
	static Color Pink(){return Color(252,197,224,255);}
	static Color Orange(){return Color(249,105,14,255);}

	//constructors
	Color(): Color(0){}
	Color(uint32_t color): mColor(color){}
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	//Operator overloading
	inline bool operator==(const Color& c) const {return mColor == c.mColor;}
	inline bool operator!=(const Color& c) const {return !(*this == c);}

	/**
	 *Returns the integer representation of the color.
	 */
	inline uint32_t GetPixelColor() const {return mColor;}

	/**
	 * Set the red, blue, green and alpha of this color object.
	 */
	void SetRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void SetRed(uint8_t red);
	void SetGreen(uint8_t green);
	void SetBlue(uint8_t blue);
	void SetAlpha(uint8_t alpha);

	uint8_t GetRed() const;
	uint8_t GetGreen() const;
	uint8_t GetBlue() const;
	uint8_t GetAlpha() const;
};



#endif /* GRAPHICS_COLOR_H_ */
;
