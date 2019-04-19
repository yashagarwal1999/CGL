#include<stdlib.h> 
#include<GL/glut.h> 
#include<fstream>
#include<iostream>
#include<math.h> 
  using namespace std;
void display();
void reshape(int,int);
void timer(int);
void intro();
void render(int x0,int y0,void* font,char* str);

int main(int argc,char** argv){

glutInit(&argc,argv);

glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);		//sets color mode
glutInitWindowPosition(200,200);	//position
glutInitWindowSize(400,400);		//size of window
glutCreateWindow("demo");		//creation

//glClearColor(1.0,1.0,0.0,1.0);        function to set bg colorr   

glutDisplayFunc(display);	//to redraw window
glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
glutMainLoop();			//to keep prog running infinitely

}

float y=10,y2=10,y3=10,y4=10,topy=-12;
int flag=1;

void display(){
glClear(GL_COLOR_BUFFER_BIT);	//clear entire frame buffer

intro();
//glPointSize(10.0);
// specify vertices from begin to end
glBegin(GL_QUADS);

glColor3f(1.0,0,0);
glVertex2f(2,y);
glVertex2f(-2,y);
glVertex2f(-2,y+2);
glVertex2f(2,y+2);

if(flag>1){
glColor3f(0,1.0,0);
glVertex2f(2,y2);
glVertex2f(-2,y2);
glVertex2f(-2,y2+2);
glVertex2f(2,y2+2);
}

if(flag>2){
glColor3f(0,0,1.0);
glVertex2f(2,y3);
glVertex2f(-2,y3);
glVertex2f(-2,y3+2);
glVertex2f(2,y3+2);
}

if(flag>3 &&flag<=5){
glColor3f(0,0,1.0);
glVertex2f(2,y4);
glVertex2f(-2,y4);
glVertex2f(-2,y4+2);
glVertex2f(2,y4+2);
}

if(flag>5){
glColor3f(1.0,1.0,0);
glVertex2f(2,y4);
glVertex2f(-2,y4);
glVertex2f(-2,y4+2);
glVertex2f(2,y4+2);
}

glEnd();

//glFlush();			//draw on screen
glutSwapBuffers();
}

void reshape(int w,int h){

//viewport
glViewport(0,0,(GLsizei)w,(GLsizei)h);	//provide coordinate for viewport

//projection
glMatrixMode(GL_PROJECTION);
glLoadIdentity();		//reset any prev matrix tranformation
gluOrtho2D(-10,10,-10,10);
glMatrixMode(GL_MODELVIEW);

}


void timer(int a){

glutPostRedisplay();
glutTimerFunc(1000/60,timer,0);

switch(flag){
case 1:
if(y>=-8)
	y=y-0.15;
else
	flag=2;
break;
case 2://gr
topy=-7;
if(y2>=-5.9)
	y2=y2-0.15;
else 
	flag=3;
break;

case 3://bl
topy=-5;
if(y3>=-3.8)
	y3=y3-0.15;
else 
	flag=4;
break;
case 4://bl
topy=-3;
if(y4>=-1.8)
	y4=y4-0.15;
else
	flag=5	;
break;
case 5://-bl
topy=-1;
if(y4<=12)
	y4=y4+0.15;
else 
	flag=6;
if(y4>0)  topy=-3;

break;
case 6://y
topy=-3;
if(y4>=-1.8)
	y4=y4-0.15;
else 
	flag=7;
break;
case 7://-y
topy=-1;
if(y4<=12)
	y4=y4+0.15;
else 
	flag=8;
if(y4>0) topy=-3;

break;
case 8://-bl
topy=-5;
if(y3<=12)
	y3=y3+0.15;
else
	flag=9;
break;
case 9://-gr
topy=-7;
if(y2<=12)
	y2=y2+0.15;
else 
	flag=10;
break;
case 10://-red
topy=-12;
if(y<=12)
	y=y+0.15;
else flag=1;
break;
}

}


void intro(){
glColor3f(1,1,1);
char buf[50]={'0'};

sprintf(buf, "<====TOP");
render(3,topy,GLUT_BITMAP_TIMES_ROMAN_24,buf);

if(flag>=1){
sprintf(buf, "PUSH Red");
render(-9,9,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

if(flag>=2){
sprintf(buf, "PUSH green");
render(-9,8,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

if(flag>=3){
sprintf(buf, "PUSH blue");
render(-9,7,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

if(flag>=4){
sprintf(buf, "PUSH blue");
render(-9,6,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}


if(flag>=5){
sprintf(buf, "POP blue");
render(-9,5,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}


if(flag>=6){
sprintf(buf, "PUSH yellow");
render(-9,4,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}


if(flag>=7){
sprintf(buf, "POP yellow");
render(-9,3,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

if(flag>=8){
sprintf(buf, "POP blue");
render(-9,2,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

if(flag>=9){
sprintf(buf, "POP green");
render(-9,1,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}


if(flag>=10){
sprintf(buf, "POP red");
render(-9,0,GLUT_BITMAP_TIMES_ROMAN_24,buf);
}

}

void render(int x0,int y0,void* font,char* str){
char* c;
glRasterPos2f(x0,y0);
for(c=str; *c!='\0'; c++){
glutBitmapCharacter(font,*c);
}

}

