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

Image *img1,*img2;
using namespace std;
#include "Image.h"
Image *img;
Car *x[100];
Car *x1[100];
Car *x2[100];
Car *x3[100];


int z=0;
queue <Car*> timeLine;
queue <Car*> timeLine1;
queue <Car*> timeLine2;
queue <Car*> timeLine3;
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
//	img->display ( 0 , 0 ) ;
	glBegin(GL_POLYGON);			//hor.street
		glColor3f(0.1,0.20,0.30);
		glVertex2i( 0 , 223 );
		glVertex2i( 0 , 281 );
		glVertex2i( 1440  , 281 );
		glVertex2i( 1440  , 223  );
	glEnd();
	glBegin(GL_POLYGON);			//ver.street
		glColor3f(0.3,0.20,0.10);
		glVertex2i( 675 , 0 );
		glVertex2i( 765 , 0 );
		glVertex2i( 765 , 900 );
		glVertex2i( 675 , 900  );
	glEnd();
	glPopMatrix ( ) ;
	for(int i=0 ;i<timeLine.size() ;i++)
		{
			Car *temp;
			temp=timeLine.front(); // get every car then procces on it
			timeLine.pop();
			temp->Display();

			timeLine.push(temp);
		}
	for(int i=0 ;i<timeLine1.size() ;i++)
		{
			Car *temp;
			temp=timeLine1.front(); // get every car then procces on it
			timeLine1.pop();
			temp->Display();
			timeLine1.push(temp);
		}
	for(int i=0 ;i<timeLine2.size() ;i++)
		{
			Car *temp;
			temp=timeLine2.front(); // get every car then procces on it
			timeLine2.pop();
			temp->Display();
			timeLine2.push(temp);
		}
	for(int i=0 ;i<timeLine3.size() ;i++)
		{
			Car *temp;
			temp=timeLine3.front(); // get every car then procces on it
			timeLine3.pop();
			temp->Display();
			timeLine3.push(temp);
		}
	glFlush();
}
void avoidColl(int val)
{
	int prevx;
	int prevy;
	if(timeLine.size()>0)
	if (timeLine.front()->swest.y > 800)
		timeLine.pop();
	if(timeLine1.size()>0)
		if (timeLine1.front()->swest.y <30)
			timeLine1.pop();
	if(timeLine2.size()>0)
			if (timeLine2.front()->swest.x >1310)
				timeLine2.pop();
	if(timeLine3.size()>0)
			if (timeLine3.front()->swest.x <30)
				timeLine3.pop();
	for(int i=0 ;i<timeLine.size() ;i++)
	{
		Car *temp;
		temp=timeLine.front(); // get every car then procces on it
		timeLine.pop();
		if(i!=0)
		{
			if(((temp->swest.y + temp->height) > (prevy-20))  )
				temp->mov=0;
		}
		prevy=temp->swest.y;
		timeLine.push(temp); // get it back

	}
	for(int i=0 ;i<timeLine1.size() ;i++)
	{
		Car *temp;
		temp=timeLine1.front(); // get every car then procces on it
		timeLine1.pop();
		if(i!=0)
		{
			if(((temp->swest.y - temp->height) < (prevy+20))  )
				temp->mov=0;
		}
		prevy=temp->swest.y;
		timeLine1.push(temp); // get it back
	}

	for(int i=0 ;i<timeLine2.size() ;i++)
	{
		Car *temp;
		temp=timeLine2.front(); // get every car then procces on it
		timeLine2.pop();
		if(i!=0)
		{
			if(((temp->swest.x + temp->width) > (prevx-20))  )
				temp->mov=0;
		}
		prevx=temp->swest.x;
		timeLine2.push(temp); // get it back
	}
	for(int i=0 ;i<timeLine3.size() ;i++)
	{
		Car *temp;
		temp=timeLine3.front(); // get every car then procces on it
		timeLine3.pop();
		if(i!=0)
		{
			if(((temp->swest.x - temp->width) < (prevx+20))  )
				temp->mov=0;
		}
		prevx=temp->swest.x;
		timeLine3.push(temp); // get it back
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
			++*temp;
			++*temp;
			timeLine.push(temp); // get it back
		}
	for(int i=0 ;i<timeLine1.size() ;i++)
		{
			Car *temp;
			temp=timeLine1.front(); // get every car then procces on it
			timeLine1.pop();
			++*temp; // move the object four times
			++*temp;
			++*temp;
			timeLine1.push(temp); // get it back
		}
	for(int i=0 ;i<timeLine2.size() ;i++)
		{
			Car *temp;
			temp=timeLine2.front(); // get every car then procces on it
			timeLine2.pop();
			++*temp; // move the object four times
			++*temp;
			++*temp;
			timeLine2.push(temp); // get it back
		}
	for(int i=0 ;i<timeLine3.size() ;i++)
		{
			Car *temp;
			temp=timeLine3.front(); // get every car then procces on it
			timeLine3.pop();
			++*temp; // move the object four times
			++*temp;
			++*temp;
			timeLine3.push(temp); // get it back
		}
	glutPostRedisplay();
	glutTimerFunc(15 , moveCars , 2);
}
void RedCheck(int val)
{
	if(RED)
	{
		for(int i=0 ; i < timeLine.size() ;i++)
		{
			Car *temp;
			temp=timeLine.front();
			timeLine.pop();
			//cout << temp->swest.x;
			if((temp->swest.y+temp->height) > 220  && (temp->swest.y+temp->height) < 225)
							temp->mov=0;

			timeLine.push(temp);
		}
		for(int i=0 ; i < timeLine1.size() ;i++)
		{
			Car *temp;
			temp=timeLine1.front();
			timeLine1.pop();
			//cout << temp->swest.x;
			if((temp->swest.y) > 282  && (temp->swest.y) < 290)
							temp->mov=0;

			timeLine1.push(temp);
		}
		for(int i=0 ;i<timeLine2.size() ;i++)
		{
			Car *temp;
			temp=timeLine2.front();
			timeLine2.pop();
			cout << temp->swest.x;
			if((temp->swest.x) > 600  && (temp->swest.x) < 620)
							temp->mov=0;
			timeLine2.push(temp);
		}
		for(int i=0 ;i<timeLine3.size() ;i++)
		{
			Car *temp;
			temp=timeLine3.front();
			timeLine3.pop();
	//		cout << temp->swest.x;
			if((temp->swest.x) > 765  && (temp->swest.x) < 772)
							temp->mov=0;
			timeLine3.push(temp);
		}
	}
	else
	{
		for(int i=0 ;i<timeLine.size() ;i++)
		{
				Car *temp;
				temp=timeLine.front();
				timeLine.pop();
				temp->mov=1;
				timeLine.push(temp);
		}
		for(int i=0 ;i<timeLine1.size() ;i++)
		{
				Car *temp;
				temp=timeLine1.front();
				timeLine1.pop();
				//cout << temp->swest.x;
				temp->mov=1;
				timeLine1.push(temp);
		}
		for(int i=0 ;i<timeLine2.size() ;i++)
		{
				Car *temp;
				temp=timeLine2.front();
				timeLine2.pop();
				temp->mov=1;
				timeLine2.push(temp);
		}
		for(int i=0 ;i<timeLine3.size() ;i++)
		{
				Car *temp;
				temp=timeLine3.front();
				timeLine3.pop();
				temp->mov=1;
				timeLine3.push(temp);
		}
	}
	//glutPostRedisplay();
	glutTimerFunc(30 , RedCheck , 2);
}
void t1(int val)
{
	RED=!RED;
	glutTimerFunc(1500 , t1 , 2);
}
void makeCar_ver(int val)
{
	static int i =0,z;
	x[i]= new Car(44,33,1,0,img2);
	x[i]->mov=1;
	timeLine.push(x[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=7;
	if(i%3==0)
		z*=8;
	glutTimerFunc(z , makeCar_ver , 2);
	}
}
void makeCar_ver2(int val)
{
	static int i =0,z;
	x1[i]= new Car(44,33,0,0,img2);
	x1[i]->mov=1;
	timeLine1.push(x1[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=7;
	if(i%3==0)
		z*=8;
	glutTimerFunc(z , makeCar_ver2 , 2);
	}
}
void makecar_hor(int val)
{
	static int i =0,z;
	x2[i]= new Car(37,64,1,1,img1);
	x2[i]->mov=1;
	timeLine2.push(x2[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=6;
	if(i%4==0)
		z*=9;
	glutTimerFunc(z , makecar_hor , 2);
	}
}
void makecar_hor2(int val)
{
	static int i =0,z;
	x3[i]= new Car(37,64,0,1,img1);
	x3[i]->mov=1;
	timeLine3.push(x3[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=6;
	if(i%4==0)
		z*=9;
	glutTimerFunc(z , makecar_hor2 , 2);
	}
}
int main (int argc,char ** argv) {
	img = new Image("background.bmp");

	img1 = new Image("carleft.bmp");
	img2 = new Image("carfront.bmp");
	RED=true;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	glutInit(&argc,argv);
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	    glutInitWindowSize(1200,750);
	    glutInitWindowPosition(50,50);
	    glutCreateWindow("OpenGl Template");

	    myStyleInit();
	    glutTimerFunc(40 , moveCars , 2);  //it moves every car according to its state
	    glutTimerFunc(40 , RedCheck , 2); // check if it is red , if it is red and car is range it will stop it
	   RED=1;
	    // glutTimerFunc(1500 , t1 , 2);
	    glutTimerFunc(40 , avoidColl , 2);
	    glutTimerFunc(500,makeCar_ver,2);
	    glutTimerFunc(500,makeCar_ver2,2);
	    glutTimerFunc(500,makecar_hor,2);
	    glutTimerFunc(500,makecar_hor2,2);
	    glutDisplayFunc(myDisplay);
	    glutMainLoop();

	return 0;
}
