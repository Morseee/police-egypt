/*
 * Image.h
 *
 *  Created on: Apr 27, 2012
 *      Author: amro
 */
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#ifndef IMAGE_H_
#define IMAGE_H_
struct RGB
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};
class Image {
private:
	RGB pixels[2048][2048];
	int width;
	int height;
public:
	Image(std::string);
	void display (int , int);
};
#endif
