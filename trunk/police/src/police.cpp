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
#include <deque>
#include <list>
#include <queue>

using namespace std;
#include "Image.h"
Image *img;
Car *x;
int z=0;
queue <Car*> timeLine;
bool RED;
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
	z++;
	glClear ( GL_COLOR_BUFFER_BIT ) ;
	glMatrixMode ( GL_MODELVIEW ) ;
	glLoadIdentity ( ) ;
	glPointSize ( 4.0 ) ;
	glPushMatrix ( ) ;
	//img->display ( 0 , 0 ) ;
	glPopMatrix ( ) ;
	for(int i=0 ;i<timeLine.size() ;i++)
		{
			Car *temp;
			temp=timeLine.front(); // get every car then procces on it
			timeLine.pop();
			temp->Display();
			timeLine.push(temp);
		}
	glFlush();
	//glutSwapBuffers ( ) ;



}
void avoidColl(int val)
{
	int prevx;
	int prevy;
	for(int i=0 ;i<timeLine.size() ;i++)
	{
		Car *temp;
		temp=timeLine.front(); // get every car then procces on it
		timeLine.pop();
		if(i!=0)
		{
			if(((temp->swest.x + temp->width) > (prevx-20))  )
				temp->mov=0;

		}
		prevx=temp->swest.x;

		if(temp->swest.x <1200)
		timeLine.push(temp); // get it back

	}
	glutTimerFunc(30 , avoidColl , 2);
}
void moveCars(int val)
{

	for(int i=0 ;i<timeLine.size() ;i++)
		{
			Car *temp;
			temp=timeLine.front(); // get every car then procces on it
			timeLine.pop();
			++*temp; // move the object four times
			++*temp;glPushMatrix ( ) ;
			++*temp;
			++*temp;
			++*temp;
			if(temp->swest.x <1200)
			timeLine.push(temp); // get it back

		}

	glutPostRedisplay();
	glutTimerFunc(30 , moveCars , 2);

}
void RedCheck(int val)
{
	if(RED)
	for(int i=0 ;i<timeLine.size() ;i++)
	{
		Car *temp;
		temp=timeLine.front();
		timeLine.pop();
		cout << temp->swest.x;
		if((temp->swest.x) > 600  && (temp->swest.x) < 620)
			temp->mov=0;
		timeLine.push(temp);

	}
	else
		for(int i=0 ;i<timeLine.size() ;i++)
			{
				Car *temp;
				temp=timeLine.front();
				timeLine.pop();
				cout << temp->swest.x;
				temp->mov=1;
				timeLine.push(temp);

			}

	//glutPostRedisplay();
	glutTimerFunc(30 , RedCheck , 2);

}
void t1(int val)
{
	RED=false;
}
int main (int argc,char ** argv) {
	img = new Image("background.bmp");
	Image *img1;
	img1 = new Image("carleft.bmp");
	RED=true;
	x = new Car(37,64,1,1,img1);
	Car *x2 = new Car(37,63,1,1,img1);

	x->mov=1;
    x2->mov=1;
	timeLine.push(x);
	timeLine.push(x2);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	glutInit(&argc,argv);
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	    glutInitWindowSize(1200,750);
	    glutInitWindowPosition(50,50);
	    glutCreateWindow("OpenGl Template");

	    myStyleInit();
	    glutTimerFunc(40 , moveCars , 2);  //it moves every car according to its state
	    glutTimerFunc(40 , RedCheck , 2); // check if it is red , if it is red and car is range it will stop it
	    glutTimerFunc(4000 , t1 , 2);
	    glutTimerFunc(40 , avoidColl , 2);
	    glutDisplayFunc(myDisplay);
	    glutMainLoop();

	return 0;
}
