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
point screen_res;
using namespace std;
#include "Image.h"
#include "Door.h"
Image *img;
Car *x[100];
Car *x1[100];
Car *x2[100];
Car *x3[100];
Car *x4[100];
Car *x5[100];
int z=0;
Door *amr;
static int level;
int Carhor_hight=35,Carhor_width=50;
int Carver_hight=40,Carver_width=32;
static int posx[2] ={300,380},posy[2]    ={560,640};
static int posx2[2]={320,380},posy2[2][2]={{340,400},{780,840}};
queue <Car*> timeLine;
queue <Car*> timeLine1;
queue <Car*> timeLine2;
queue <Car*> timeLine3;
queue <Car*> timeLine4;
queue <Car*> timeLine5;
bool RED,RED1;
void myStyleInit()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,screen_res.x,0,screen_res.y,0,-1);
}
void myDisplay2()
{
	int wide =60,xfc=-30,yfc=-20;
	int fl1=wide,fl2l=350,fl2u=410;	//floor position at y-axis
	int ceil1=fl2l-wide,ceil2=screen_res.y-wide;
	int wid,hit,hit2,fram;//for picture all *2

	glClear ( GL_COLOR_BUFFER_BIT ) ;
	glMatrixMode ( GL_MODELVIEW ) ;
	glLoadIdentity ( ) ;
	glPointSize ( 4.0 ) ;

	glPushMatrix ( ) ;
	glColor3f(0.2,0.5,0.4);

	glBegin(GL_POLYGON);				//1st floor
		glColor3f(0.5429,0.71484375,0.7343);
		glVertex2i(0,0);
		glVertex2i(screen_res.x,0);
		glVertex2i(screen_res.x,fl1);
		glVertex2i(0,fl1);
	glEnd();

	glBegin(GL_POLYGON);				//2nd floor
		glVertex2i(0,fl2l);
		glVertex2i(screen_res.x,fl2l);
		glVertex2i(screen_res.x,fl2u);
		glVertex2i(0,fl2u);
	glEnd();

	glBegin(GL_LINES);						//draw lines
		glColor3f(0,0,0);//black
		glVertex2i(0,fl1);		//upper border of 1st floor
		glVertex2i(screen_res.x,fl1);

		glVertex2i(0,fl2l);					//lower border of 2nd floor
		glVertex2i(screen_res.x,fl2l);

		glVertex2i(0,ceil1+(wide/3));		//1st cut off ceil in 1st floor
		glVertex2i(screen_res.x,ceil1+(wide/3));

		glVertex2i(0,fl2l-(wide/3));		//2nd cut off ceil in 1st floor
		glVertex2i(screen_res.x,fl2l-(wide/3));


		glVertex2i(0,fl2u);					//upper border of 2nd floor
		glVertex2i(screen_res.x,fl2u);

		for(int i=-70;i<screen_res.x;i+=30)//1st floor ground
		{
			glVertex2i(i,0);
			glVertex2i(i+70,fl1);
		}
		for(int i=-60;i<screen_res.x;i+=30)//2nd floor ground
		{
			glVertex2i(i,fl2l);
			glVertex2i(i+60,fl2u);
		}
	glEnd();				//End draw lines

	glPushMatrix();			//ceil in 1st floor
	glBegin(GL_POLYGON);
	glColor3f(0.4140625,0.2734375,0);
	glVertex2i(0,ceil1);
	glVertex2i(screen_res.x,ceil1);
	glVertex2i(screen_res.x,fl2l);
	glVertex2i(0,fl2l);
	glEnd();
	glPushMatrix();			//wall in 1st floor
	glBegin(GL_POLYGON);
	glColor3f(0.99609375,.8984375,0.796875);
	glVertex2i(0,fl1);
	glVertex2i(screen_res.x,fl1);
	glVertex2i(screen_res.x,ceil1);
	glVertex2i(0,ceil1);
	glEnd();
	glPopMatrix();			//End wall in 1st floor

	glPushMatrix();//table
	glTranslatef(370,90,0);//position from NEast pt
	glBegin(GL_POLYGON);//leg
	glColor3f(0.1,0.5,0.24);
	glVertex2i(-150,-10);
	glVertex2i(-150,-45);
	glVertex2i(-142,-45);
	glVertex2i(-142,-10);
	glEnd();
	glBegin(GL_POLYGON);//leg
	glColor3f(0.1,0.5,0.24);
	glVertex2i(-150,-10);
	glVertex2i(-156,-14);
	glVertex2i(-156,-49);
	glVertex2i(-150,-45);
	glEnd();
	glBegin(GL_POLYGON);//Surface
	glColor3f(0.15,0.75,0.324);
	glVertex2i(0,0);
	glVertex2i(-30,-20);
	glVertex2i(-180,-20);
	glVertex2i(-150,0);
	glEnd();
	glBegin(GL_POLYGON);//side
	glColor3f(0.1,0.5,0.24);
	glVertex2i(0,0);
	glVertex2i(-30,-20);
	glVertex2i(-30,-30);
	glVertex2i(0,-10);
	glEnd();
	glBegin(GL_POLYGON);//side
	glColor3f(0.1,0.5,0.24);
	glVertex2i(-30,-20);
	glVertex2i(-180,-20);
	glVertex2i(-180,-30);
	glVertex2i(-30,-30);
	glEnd();
	glBegin(GL_POLYGON);//leg
	glColor3f(0.1,0.5,0.24);
	glVertex2i(0,-10);
	glVertex2i(0,-45);
	glVertex2i(-6,-49);
	glVertex2i(-6,-14);
	glEnd();
	glBegin(GL_POLYGON);//leg
	glColor3f(0.1,0.5,0.24);
	glVertex2i(-30,-30);
	glVertex2i(-38,-30);
	glVertex2i(-38,-65);
	glVertex2i(-30,-65);
	glEnd();
	glBegin(GL_POLYGON);//leg
	glColor3f(0.1,0.5,0.24);
	glVertex2i(-30,-30);
	glVertex2i(-30,-65);
	glVertex2i(-24,-61);
	glVertex2i(-24,-26);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.5,0.24);//leg
	glVertex2i(-180,-30);
	glVertex2i(-180,-65);
	glVertex2i(-172,-65);
	glVertex2i(-172,-30);
	glEnd();
	glPopMatrix();//End Table

	glPushMatrix();			//1st window
	glTranslatef(400,ceil1-50,0);
	glBegin(GL_POLYGON);
	wid=-200;hit=-90;fram=7.5;
	glBegin(GL_POLYGON);//frame
	glColor3f(0.0,0.0,0.0);
	glVertex2i(0,0);
	glVertex2i(wid,0);
	glVertex2i(wid,hit);
	glVertex2i(0,hit);
	glEnd();
	glBegin(GL_POLYGON);//pic
	glColor3f(0,0.6,0.7);
	wid+=fram;hit+=fram;
	glVertex2i(-fram,-fram);
	glVertex2i(wid,-fram);
	glVertex2i(wid,hit);
	glVertex2i(-fram,hit);
	glEnd();
	glPopMatrix();			//End 1st window



	//2nd floor

	glPushMatrix();			//ceil in 2nd floor
	glBegin(GL_POLYGON);
	glColor3f(0.8984375,0.8984375,0.8984375);
	glVertex2i(0,ceil2);
	glVertex2i(screen_res.x,ceil2);
	glVertex2i(screen_res.x,screen_res.y);
	glVertex2i(0,screen_res.y);
	glEnd();
	glPopMatrix();			//End ceil in 2nd floor

	glPushMatrix();			//wall in 2nd floor
	glBegin(GL_POLYGON);
	glColor3f(0.99609375,.8984375,0.796875);
	glVertex2i(0,fl2u);
	glVertex2i(screen_res.x,fl2u);
	glVertex2i(screen_res.x,ceil2);
	glVertex2i(0,ceil2);
	glEnd();
	glPopMatrix();			//End wall in 2nd floor

	glPushMatrix();			//picture 1
	wid=90;hit=-10;hit2=-110;fram=7.5;//all *2
	glTranslatef(950,ceil1-15,0);//Position of the picture
	glBegin(GL_POLYGON);	//1st side line
	glColor3f(0,0,0);
	glVertex2i(0,0);
	glVertex2i(0,5);
	glVertex2i(wid-25,hit);
	glVertex2i(wid-30,hit);
	glEnd();
	glBegin(GL_POLYGON);	//2nd side lien
	glColor3f(0,0,0);
	glVertex2i(0,0);
	glVertex2i(0,5);
	glVertex2i(-wid+25,hit);
	glVertex2i(-wid+30,hit);
	glEnd();
	glBegin(GL_POLYGON);//frame
	glColor3f(0.8046875,0.76171875,0.26171875);
	glVertex2i(wid,hit);
	glVertex2i(-wid,hit);
	glVertex2i(-wid,hit2);
	glVertex2i(wid,hit2);
	glEnd();
	glBegin(GL_POLYGON);//pic
	glColor3f(0,0.6,0);
	wid-=fram;hit-=fram;hit2+=fram;
	glVertex2i(wid,hit);
	glVertex2i(-wid,hit);
	glVertex2i(-wid,hit2);
	glVertex2i(wid,hit2);
	glEnd();
	glPopMatrix();		//picture 1

	glPushMatrix();			//1st cupboard
	int wd=-150,ht=-(ceil2-fl2u);
	glTranslatef(-ht,ceil2,0);
	glBegin(GL_POLYGON);	//ceil
	glColor3f(00.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(wd,0);
	glVertex2i(wd+xfc,yfc);
	glVertex2i(xfc,yfc);
	glEnd();
	glBegin(GL_POLYGON);	//side
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(xfc,yfc);
	glVertex2i(xfc,ht+yfc);
	glVertex2i(0,ht);
	glEnd();
	glBegin(GL_POLYGON);	//front
	glColor3f(0.4296875,0.21484375,0);
	glVertex2i(xfc,yfc);
	glVertex2i(wd+xfc,yfc);
	glVertex2i(wd+xfc,ht+yfc);
	glVertex2i(xfc,ht+yfc);
	glEnd();
	glBegin(GL_POLYGON);	//lower cut
	glColor3f(0.3125,0.15625,0);
	glVertex2i(xfc,ht+yfc+32.5);
	glVertex2i(xfc,ht+yfc+27.5);
	glVertex2i(xfc+wd,ht+yfc+27.5);
	glVertex2i(xfc+wd,ht+yfc+32.5);
	glEnd();
	glBegin(GL_POLYGON);	//center cut
	glColor3f(0.3125,0.15625,0);
	glVertex2i(xfc+(wd/2)-2.5,yfc);
	glVertex2i(xfc+(wd/2)+2.5,yfc);
	glVertex2i(xfc+(wd/2)+2.5,ht+yfc);
	glVertex2i(xfc+(wd/2)-2.5,ht+yfc);
	glEnd();
	glPopMatrix();			//End 1st cupboard

	glPushMatrix();			//2nd cupboard
	wd=-160;ht=-70;
	glTranslatef(980,ceil2-130,0);
	glBegin(GL_POLYGON);	//ceil
	glColor3f(00.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(wd,0);
	glVertex2i(wd+xfc,yfc);
	glVertex2i(xfc,yfc);
	glEnd();
	glBegin(GL_POLYGON);	//side
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(xfc,yfc);
	glVertex2i(xfc,ht+yfc);
	glVertex2i(0,ht);
	glEnd();
	glBegin(GL_POLYGON);	//front frame
	glColor3f(0.3796875,0.20484375,0);
	glVertex2i(xfc,yfc);
	glVertex2i(wd+xfc,yfc);
	glVertex2i(wd+xfc,ht+yfc);
	glVertex2i(xfc,ht+yfc);
	glEnd();
	glEnd();
	glBegin(GL_POLYGON);	//front
	glColor3f(0.4296875,0.20484375,0);
	glVertex2i(xfc-fram,yfc-fram);
	glVertex2i(wd+xfc+fram,yfc-fram);
	glVertex2i(wd+xfc+fram,ht+yfc+fram);
	glVertex2i(xfc-fram,ht+yfc+fram);
	glEnd();
	glBegin(GL_POLYGON);	//lower cut
	glColor3f(0.3125,0.15625,0);
	glVertex2i(xfc-fram,ht+yfc+31.5);
	glVertex2i(xfc-fram,ht+yfc+28.5);
	glVertex2i(xfc+wd+fram,ht+yfc+28.5);
	glVertex2i(xfc+wd+fram,ht+yfc+31.5);
	glEnd();
	glBegin(GL_POLYGON);	//leg
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);	//leg
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);	//leg
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);	//leg
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);	//leg
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glEnd();
	glBegin(GL_POLYGON);	//leg
	glColor3f(0.3125,0.15625,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glVertex2i(0,0);
	glEnd();
	glPopMatrix();			//End 2nd cupboard

	glPushMatrix();			//2nd window
	glTranslatef(1000,ceil2-30,0);
	glBegin(GL_POLYGON);
	wid=-200;hit=-90;fram=7.5;
	glBegin(GL_POLYGON);//frame
	glColor3f(0.0,0.0,0.0);
	glVertex2i(0,0);
	glVertex2i(wid,0);
	glVertex2i(wid,hit);
	glVertex2i(0,hit);
	glEnd();
	glBegin(GL_POLYGON);//pic
	glColor3f(0,0.6,0.7);
	wid+=fram;hit+=fram;
	glVertex2i(-fram,-fram);
	glVertex2i(wid,-fram);
	glVertex2i(wid,hit);
	glVertex2i(-fram,hit);
	glEnd();
	glPopMatrix();			//End 2nd window



	glBegin(GL_LINES);						//draw lines
		glColor3f(0,0,0);//black
		glPointSize(10.0);
		glVertex2i(0,ceil1+(wide/3));		//1st cut off ceil in 1st floor
		glVertex2i(screen_res.x,ceil1+(wide/3));

		glVertex2i(0,fl2l-(wide/3));		//2nd cut off ceil in 1st floor
		glVertex2i(screen_res.x,fl2l-(wide/3));

		for(int i=-10;i<screen_res.x+50;i+=60)//1st floor ground
		{
			glVertex2i(i,ceil1);
			glVertex2i(i,ceil1+(wide/3));
		}
		for(int i=-40;i<screen_res.x+10;i+=60)//1st floor ground
		{
			glVertex2i(i,ceil1+(wide/3));
			glVertex2i(i,fl2l-(wide/3));
		}
		for(int i=-10;i<screen_res.x+50;i+=60)//1st floor ground
		{
			glVertex2i(i,fl2l-(wide/3));
			glVertex2i(i,fl2l);
		}

	glEnd();

	glPushMatrix();			//picture 2
	wid=60;hit=-10;hit2=-80;fram=7.5;//all *2
	glTranslatef(600,ceil2-15,0);//Position of the picture
	glBegin(GL_POLYGON);	//1st side line
	glColor3f(0,0,0);
	glVertex2i(0,0);
	glVertex2i(0,5);
	glVertex2i(wid-25,hit);
	glVertex2i(wid-30,hit);
	glEnd();
	glBegin(GL_POLYGON);	//2nd side lien
	glColor3f(0,0,0);
	glVertex2i(0,0);
	glVertex2i(0,5);
	glVertex2i(-wid+25,hit);
	glVertex2i(-wid+30,hit);
	glEnd();
	glBegin(GL_POLYGON);//frame
	glColor3f(0.8046875,0.76171875,0.26171875);
	glVertex2i(wid,hit);
	glVertex2i(-wid,hit);
	glVertex2i(-wid,hit2);
	glVertex2i(wid,hit2);
	glEnd();
	glBegin(GL_POLYGON);//pic
	glColor3f(0,0.6,0);
	wid-=fram;hit-=fram;hit2+=fram;
	glVertex2i(wid,hit);
	glVertex2i(-wid,hit);
	glVertex2i(-wid,hit2);
	glVertex2i(wid,hit2);
	glEnd();
	glPopMatrix();
	glPushMatrix ( ) ;
	//glColor3f(0.2,0.5,0.4);
	amr->Display();
	glPopMatrix();


	glFlush();

}
void myDisplay()
{
	z++;
	glClear ( GL_COLOR_BUFFER_BIT ) ;
	glMatrixMode ( GL_MODELVIEW ) ;
	glLoadIdentity ( ) ;
	glPointSize ( 4.0 ) ;
	glPushMatrix ( ) ;
	if(level == 0)
	{
		//img->display ( 0 , 0 ) ;
		glBegin(GL_POLYGON);			//hor.street
			glColor3f(0.1,0.20,0.30);
			glVertex2i( 0 , posx[0] );
			glVertex2i( 0 , posx[1] );
			glVertex2i( screen_res.x  , posx[1] );
			glVertex2i( screen_res.x  , posx[0]  );
		glEnd();
		glBegin(GL_POLYGON);			//ver.street
			glColor3f(0.3,0.20,0.10);
			glVertex2i( posy[0] , 0 );
			glVertex2i( posy[1] , 0 );
			glVertex2i( posy[1] , screen_res.y );
			glVertex2i( posy[0] , screen_res.y  );
		glEnd();
		glBegin(GL_POLYGON);			//Traffic Signal
			if(!RED)
			glColor3f(0.0,1.0,0.0);
			else
			glColor3f(1.0,0.0,0.0);
			glVertex2i(posy[0],posx[0]);
			glVertex2i(posy[0],posx[0]-30);
			glVertex2i(posy[0]-30,posx[0]-30);
			glVertex2i(posy[0]-30,posx[0]);
		glEnd();
		glPopMatrix ( ) ;
	}
	else if (level ==1)
	{
		glBegin(GL_POLYGON);			//hor.street
			glColor3f(0.1,0.20,0.30);
			glVertex2i( 0 , posx2[0] );
			glVertex2i( 0 , posx2[1] );
			glVertex2i( screen_res.x  , posx2[1] );
			glVertex2i( screen_res.x  , posx2[0]  );
		glEnd();
		glBegin(GL_POLYGON);			//ver.street1
			glColor3f(0.3,0.20,0.10);
			glVertex2i( posy2[0][0] , 0 );
			glVertex2i( posy2[0][1] , 0 );
			glVertex2i( posy2[0][1] , screen_res.y );
			glVertex2i( posy2[0][0] , screen_res.y  );
		glEnd();
		glBegin(GL_POLYGON);			//ver.street2
			glColor3f(0.3,0.20,0.10);
			glVertex2i( posy2[1][0] , 0 );
			glVertex2i( posy2[1][1] , 0 );
			glVertex2i( posy2[1][1] , screen_res.y );
			glVertex2i( posy2[1][0] , screen_res.y  );
		glEnd();
		glBegin(GL_POLYGON);			//Traffic Signal
			if(!RED)
			glColor3f(0.0,1.0,0.0);
			else
			glColor3f(1.0,0.0,0.0);
			glVertex2i(posy2[0][1],posx2[0]);
			glVertex2i(posy2[0][1],posx2[0]-30);
			glVertex2i(posy2[0][1]+30,posx2[0]-30);
			glVertex2i(posy2[0][1]+30,posx2[0]);
		glEnd();
		glBegin(GL_POLYGON);
			glBegin(GL_POLYGON);			//Traffic Signal
			if(RED1)
			glColor3f(0.0,1.0,0.0);
			else
			glColor3f(1.0,0.0,0.0);
			glVertex2i(posy2[1][0],posx2[0]);
			glVertex2i(posy2[1][0],posx2[0]-30);
			glVertex2i(posy2[1][0]-30,posx2[0]-30);
			glVertex2i(posy2[1][0]-30,posx2[0]);
		glEnd();
		glPopMatrix ( ) ;
	}
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
	if(level==1)
	{
		for(int i=0 ;i<timeLine4.size() ;i++)
			{
				Car *temp;
				temp=timeLine4.front(); // get every car then procces on it
				timeLine4.pop();
				temp->Display();
				timeLine4.push(temp);
			}
		for(int i=0 ;i<timeLine5.size() ;i++)
			{
				Car *temp;
				temp=timeLine5.front(); // get every car then procces on it
				timeLine5.pop();
				temp->Display();
				timeLine5.push(temp);
			}
	}
	glFlush();
}
void avoidColl(int val)
{
	int prevx;
	int prevy;
	if(timeLine.size()>0)
		if (timeLine.front()->swest.y > screen_res.y)
			timeLine.pop();
	if(timeLine1.size()>0)
		if (timeLine1.front()->swest.y <0)
			timeLine1.pop();
	if(timeLine2.size()>0)
			if (timeLine2.front()->swest.x >screen_res.x)
				timeLine2.pop();
	if(timeLine3.size()>0)
			if (timeLine3.front()->swest.x <0)
				timeLine3.pop();
	if(level==1)
	{
		if(timeLine4.size()>0)
			if (timeLine4.front()->swest.y > screen_res.y)
				timeLine4.pop();
		if(timeLine5.size()>0)
			if (timeLine5.front()->swest.y <0)
				timeLine5.pop();
		for(int i=0 ;i<timeLine4.size() ;i++)
		{
			Car *temp;
			temp=timeLine4.front(); // get every car then procces on it
			timeLine4.pop();
			if(i!=0)
			{
				if(((temp->swest.y + temp->height) > (prevy-20))  )
					temp->mov=0;
			}
			prevy=temp->swest.y;
			timeLine4.push(temp); // get it back
		}
		for(int i=0 ;i<timeLine5.size() ;i++)
		{
			Car *temp;
			temp=timeLine5.front(); // get every car then procces on it
			timeLine5.pop();
			if(i!=0)
			{
				if(((temp->swest.y - temp->height) < (prevy+20))  )
					temp->mov=0;
			}
			prevy=temp->swest.y;
			timeLine5.push(temp); // get it back
		}
	}

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
			else if(!temp->RED && !temp->RED1)
						temp->mov=1;
		}
		else if(!temp->RED && !temp->RED1)
								temp->mov=1;


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
			else if(!temp->RED && !temp->RED1)
						temp->mov=1;
		}
		else if(!temp->RED && !temp->RED1)
								temp->mov=1;

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
	if(level==1)
	{
		for(int i=0 ;i<timeLine4.size() ;i++)
			{
				Car *temp;
				temp=timeLine4.front(); // get every car then procces on it
				timeLine4.pop();
				++*temp; // move the object four times
				++*temp;
				++*temp;
				timeLine4.push(temp); // get it back
			}
		for(int i=0 ;i<timeLine5.size() ;i++)
			{
				Car *temp;
				temp=timeLine5.front(); // get every car then procces on it
				timeLine5.pop();
				++*temp; // move the object four times
				++*temp;
				++*temp;
				timeLine5.push(temp); // get it back
			}
	}
	glutPostRedisplay();
	glutTimerFunc(15 , moveCars , 2);
}
void RedCheck(int val)
{
	if(RED)
	{
		if(level==0)
		{
			for(int i=0 ; i < timeLine.size() ;i++)
			{
				Car *temp;
				temp=timeLine.front();
				timeLine.pop();
				if((temp->swest.y+temp->height) > posx[0]-10  && (temp->swest.y+temp->height) < posx[0])
								temp->mov=0;

				timeLine.push(temp);
			}
			for(int i=0 ; i < timeLine1.size() ;i++)
			{
				Car *temp;
				temp=timeLine1.front();
				timeLine1.pop();
				if((temp->swest.y) > posx[1]  && (temp->swest.y) < posx[1] + 10)
								temp->mov=0;

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
		if(level ==1)
			//static int posx2[2]={320,380},posy2[2][2]={{340,400},{780,840}};
		{
			for(int i=0 ; i < timeLine.size() ;i++)		//ver_up
			{
				Car *temp;
				temp=timeLine.front();
				timeLine.pop();
				if((temp->swest.y+temp->height) > posx2[0]-10  && (temp->swest.y+temp->height) < posx2[0])
								temp->mov=0;

				timeLine.push(temp);
			}
			for(int i=0 ; i < timeLine1.size() ;i++)	//ver_down
			{
				Car *temp;
				temp=timeLine1.front();
				timeLine1.pop();
				if((temp->swest.y) > posx2[1]  && (temp->swest.y) < posx2[1] + 10)
								temp->mov=0;

				timeLine1.push(temp);
			}
			for(int i=0 ;i<timeLine2.size() ;i++)
			{
					Car *temp;
					temp=timeLine2.front();
					timeLine2.pop();
					//temp->mov=1;
					if(temp->RED)
					{
						temp->mov=1;
						temp->RED=0;
					}
					timeLine2.push(temp);
			}
			for(int i=0 ;i<timeLine3.size() ;i++)
			{
					Car *temp;
					temp=timeLine3.front();
					timeLine3.pop();
					//temp->mov=1;
					if(temp->RED)
					{
						temp->mov=1;
						temp->RED=0;
					}
					timeLine3.push(temp);
			}

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
				temp->mov=1;
				timeLine1.push(temp);
		}
		if(level==1)
		{
		for(int i=0 ;i<timeLine2.size() ;i++)		//hoe_right
			{
				Car *temp;
				temp=timeLine2.front();
				timeLine2.pop();
				if((temp->swest.x + temp->width) > posy2[0][0] -10  && (temp->swest.x + temp->width) < posy2[0][0])
				{
								temp->mov=0;
								temp->RED=1;
				}

				timeLine2.push(temp);
			}
			for(int i=0 ;i<timeLine3.size() ;i++)		//hor_left
			{
				Car *temp;
				temp=timeLine3.front();
				timeLine3.pop();
				if((temp->swest.x) > posy2[0][1]  && (temp->swest.x) < posy2[0][1] + 10)
				{
								temp->mov=0;
								temp->RED=1;
				}
				timeLine3.push(temp);
			}
		}
		else
		{
			for(int i=0 ;i<timeLine2.size() ;i++)
						{
							Car *temp;
							temp=timeLine2.front();
							timeLine2.pop();
							if((temp->swest.x + temp->width) > posy[0] -10  && (temp->swest.x + temp->width) < posy[0])
							{				temp->mov=0;
											temp->RED=1;
							}
							timeLine2.push(temp);
						}
						for(int i=0 ;i<timeLine3.size() ;i++)
						{
							Car *temp;
							temp=timeLine3.front();
							timeLine3.pop();
							if((temp->swest.x) > posy[1]  && (temp->swest.x) < posy[1] + 10)
							{
											temp->mov=0;
											temp->RED=1;
							}
							timeLine3.push(temp);
						}

		}
	}
	if(RED1)
	{

		for(int i=0 ;i<timeLine2.size() ;i++)		//hoe_right
		{
			Car *temp;
			temp=timeLine2.front();
			timeLine2.pop();
			if((temp->swest.x + temp->width) > posy2[1][0] -10  && (temp->swest.x + temp->width) < posy2[1][0])
			{
							temp->mov=0;
							temp->RED1=1;
			}
			timeLine2.push(temp);
		}
		for(int i=0 ;i<timeLine3.size() ;i++)		//hor_left
		{
			Car *temp;
			temp=timeLine3.front();
			timeLine3.pop();
			if((temp->swest.x) > posy2[1][1]  && (temp->swest.x) < posy2[1][1] + 10)
			{
							temp->mov=0;
							temp->RED1=1;
			}
			timeLine3.push(temp);
		}
		for(int i=0 ;i<timeLine4.size() ;i++)
			{
					Car *temp;
					temp=timeLine4.front();
					timeLine4.pop();
					temp->mov=1;
					timeLine4.push(temp);
			}
			for(int i=0 ;i<timeLine5.size() ;i++)
			{
					Car *temp;
					temp=timeLine5.front();
					timeLine5.pop();
					temp->mov=1;
					timeLine5.push(temp);
			}

	}
	else
	{
		for(int i=0 ;i<timeLine2.size() ;i++)
		{
				Car *temp;
				temp=timeLine2.front();
				timeLine2.pop();
				if(temp->RED1)
				{
					temp->mov=1;
					temp->RED1=0;
				}
				timeLine2.push(temp);
		}
		for(int i=0 ;i<timeLine3.size() ;i++)
		{
				Car *temp;
				temp=timeLine3.front();
				timeLine3.pop();
				if(temp->RED1)
				{
					temp->mov=1;
					temp->RED1=0;
				}
				timeLine3.push(temp);
		}

		for(int i=0 ;i<timeLine4.size() ;i++)
		{
				Car *temp;
				temp=timeLine4.front();
				timeLine4.pop();
				temp->mov=1;
				timeLine4.push(temp);
		}
		for(int i=0 ;i<timeLine5.size() ;i++)
		{
				Car *temp;
				temp=timeLine5.front();
				timeLine5.pop();
				temp->mov=1;
				timeLine5.push(temp);
		}
		for(int i=0 ; i < timeLine4.size() ;i++)		//ver_up
			{
				Car *temp;
				temp=timeLine4.front();
				timeLine4.pop();
				if((temp->swest.y+temp->height) > posx2[0]-10  && (temp->swest.y+temp->height) < posx2[0])
								temp->mov=0;

				timeLine4.push(temp);
			}
			for(int i=0 ; i < timeLine5.size() ;i++)	//ver_down
			{
				Car *temp;
				temp=timeLine5.front();
				timeLine5.pop();
				if((temp->swest.y) > posx2[1]  && (temp->swest.y) < posx2[1] + 10)
								temp->mov=0;

				timeLine5.push(temp);
			}

	}
	//glutPostRedisplay();
	glutTimerFunc(30 , RedCheck , 2);
}

void t1(int val)
{
	amr->open();
	glutPostRedisplay();
	glutTimerFunc(30 , t1 , 2);
}
void makeCar_ver(int val)
{
	static int i =0,z;
	x[i]= new Car(Carver_hight,Carver_width,0,1,0,img2);
	x[i]->mov=1;
	timeLine.push(x[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=7;
	else if(i%3==0)
		z*=8;
	glutTimerFunc(z , makeCar_ver , 2);
	}
}
void makeCar_ver2(int val)
{
	static int i =0,z;
	x1[i]= new Car(Carver_hight,Carver_width,0,0,0,img2);
	x1[i]->mov=1;
	timeLine1.push(x1[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%11==0)
		z*=4;
	else if(i%7==0)
		z*=3;
	else if(i%4==0)
		z*=6;
	glutTimerFunc(z , makeCar_ver2 , 2);
	}
}
void makeCar_ver4(int val)
{
	static int i =0,z;
	x4[i]= new Car(Carver_hight,Carver_width,1,1,0,img2);
	x4[i]->mov=1;
	timeLine4.push(x4[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=7;
	else if(i%3==0)
		z*=8;
	glutTimerFunc(z , makeCar_ver4 , 2);
	}
}
void makeCar_ver5(int val)
{
	static int i =0,z;
	x5[i]= new Car(Carver_hight,Carver_width,1,0,0,img2);
	x5[i]->mov=1;
	timeLine5.push(x5[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%11==0)
		z*=4;
	else if(i%7==0)
		z*=3;
	else if(i%4==0)
		z*=6;
	glutTimerFunc(z , makeCar_ver5 , 2);
	}
}
void makecar_hor(int val)
{
	static int i =0,z;
	x2[i]= new Car(Carhor_hight,Carhor_width,0,1,1,img1);
	x2[i]->mov=1;
	timeLine2.push(x2[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=6;
	else if(i%4==0)
		z*=9;
	glutTimerFunc(z , makecar_hor , 2);
	}
}
void makecar_hor2(int val)
{
	static int i =0,z;
	x3[i]= new Car(Carhor_hight,Carhor_width,0,0,1,img1);
	x3[i]->mov=1;
	timeLine3.push(x3[i]);
	if(i<90)
	{i++;
	z=650;
	if(i%7==0)
		z*=6;
	else if(i%4==0)
		z*=9;
	glutTimerFunc(z , makecar_hor2 , 2);
	}
}
void mouseMove(int click, int state, int x, int y)
{



        if(click==GLUT_LEFT_BUTTON && state==GLUT_DOWN && level==1 )
        {
    		//glVertex2i(posy2[0][1],posx2[0]);
        	//cout << x <<' '  << y;
    		if(x>400 && x<430 && y>380 && y<400)
    			RED=!RED;
    		if(x>750 && x<780 && y>380 && y<400)
    		    RED1=!RED1;
        }
        if(click==GLUT_LEFT_BUTTON && state==GLUT_DOWN && level==0 )
		{
			//glVertex2i(posy2[0][1],posx2[0]);
			cout << x <<' '  << y;
			if(x>531 && x<561 && y>400 && y<430)
				RED=!RED;

		}


}

int main (int argc,char ** argv) {
    screen_res.x=1200;
    screen_res.y=700;
    level = 1;
    //Car::lev=0;
    amr= new Door(300,300,300,600,50,0,0,1,0,0);
    cout<< amr->cet;
   amr->open();
    if(level==1)
    {
    	Carhor_hight-=12;
    	Carhor_width-=20;
    	Carver_hight-=5;
    	Carver_width-=10;
    }
	img = new Image("background.bmp");
	img1 = new Image("carleft.bmp");
	img2 = new Image("carfront.bmp");
	RED=1;
    RED1=0;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	glutInit(&argc,argv);
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	    glutInitWindowSize(screen_res.x,screen_res.y);
	    glutInitWindowPosition(100,100);
	    glutCreateWindow("OpenGl Template");

	    myStyleInit();
	    //glutTimerFunc(40 , moveCars , 2);  //it moves every car according to its state
	    //glutTimerFunc(40 , RedCheck , 2); // check if it is red , if it is red and car is range it will stop it
	    glutTimerFunc(1 , t1 , 2);
	    //glutTimerFunc(40 , avoidColl , 2);
	    //glutTimerFunc(500,makeCar_ver,2);
	    //glutTimerFunc(500,makeCar_ver2,2);
	    if(level==1)
	    {
	   // glutTimerFunc(500,makeCar_ver4,2);
	  //  glutTimerFunc(500,makeCar_ver5,2);
	    }
	   // glutMouseFunc( mouseMove );
	 //   glutTimerFunc(500,makecar_hor,2);
	//    glutTimerFunc(500,makecar_hor2,2);
	    glutDisplayFunc(myDisplay2);
	    glutMainLoop();

	return 0;
}
