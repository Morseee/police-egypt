//============================================================================
// Name        : police.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include "Car.h"
using namespace std;
#include "Image.h"
Image *img;
Car *x;
void myStyleInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,1440,0,900,0,-1);
}
void myDisplay()
{
	glClear ( GL_COLOR_BUFFER_BIT ) ;
	glMatrixMode ( GL_MODELVIEW ) ;
	glLoadIdentity ( ) ;
	glPointSize ( 4.0 ) ;
	glPushMatrix ( ) ;
	img->display ( 0 , 0 ) ;
	glPopMatrix ( ) ;
	x->Display();
	//glFlush();
	glutSwapBuffers ( ) ;



}
void myTimer(int val)
{

	x->swest.x++;
	glutPostRedisplay();
	glutTimerFunc(1 , myTimer , 0);

}
int main (int argc,char ** argv) {
	img = new Image("background.bmp");
	Image *img1;
	img1 = new Image("carleft.bmp");

	x = new Car(37,46,0,1,img1);
	x->mov=1;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	glutInit(&argc,argv);
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	    glutInitWindowSize(1200,750);
	    glutInitWindowPosition(50,50);
	    glutCreateWindow("OpenGl Template");

	    myStyleInit();
	    glutTimerFunc(1 , myTimer , 0);
	    glutDisplayFunc(myDisplay);
	    glutMainLoop();

	return 0;
}
