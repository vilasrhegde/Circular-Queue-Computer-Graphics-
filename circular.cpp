#include<stdlib.h>
#include<stdio.h>
#include<glut.h>
#include<string.h>

void keyboard(unsigned char key, int a, int b);
void mainMenu();
void drawstring(GLfloat x, GLfloat y, const char* string);
void* currentfont;

void insert();

void display1(void);




void setFont(void* font)
{
	currentfont = font;
}
void init(void)
{
	glClearColor(0, 0, 0, 0);
	glLineWidth(7);
	glColor3f(0.65, 0.65, 0.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
}



void drawstring(GLfloat x, GLfloat y, const char* string)
{
	const char* c;
	glRasterPos2f(x, y);
	for (c = string;*c != '\0';c++)
	{
		glutBitmapCharacter(currentfont, *c);
	}
}

void drawBold(GLfloat x,GLfloat y,GLfloat z,const char* string){
	glTranslatef(x,y,z);
	glScaled(0.17,0.3,0.0);

	const char* c;
	for (c = string;*c != '\0';c++)
	{
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,*c);
	}
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	//drawstring(230, 400, "SDM INSTITUTE OF TECHNOLOGY, UJIRE");

	glColor3f(0.5, 1, 1.0);
	drawstring(225, 343, "A COMPUTER GRAPHICS MINI PROJECT ON");
	glColor3f(1.0, 1.0, 1.0);
	drawstring(213, 313, "------| CIRCULAR QUEUE OPERATIONS |-------");

	glColor3f(1, 0.0, 0.3);
	drawstring(45, 210, "SUBMITTED BY:");
	glColor3f(0.5, 1.0, 0.5);
	drawstring(45, 150, "Mr. Abdul Imad(4SU20CS400)");
	drawstring(45, 130, "Ms. Shruti(4SU20CS407)");
	drawstring(45, 110, "Mr. Sunil Naik(4SU20CS408)");
	drawstring(45, 170, "Mr. Vilas Hegde(4SU19CS111)");

	
	glColor3f(1, 0.0, 0.3);
	drawstring(513, 195, "GUIDED BY:");
	glColor3f(0.5, 1.0, 0.5);
	drawstring(513, 170, "Prof.Arjun K");
	
	glColor3f(0.0, 0.8, 0.9);
	drawstring(470, 90, "PRESS ENTER TO START");
	glColor3f(1.0, 1.0, 0.0);

	glPushMatrix();
	drawBold(15.0, 400.0,0.0, "SDM INSTITUTE OF TECHNOLOGY, UJIRE");
	glPopMatrix();

	//glutMouseFunc(mouse);
	glFlush();
}
//glutSwapBuffers();

//----------------------------------------------------------------copied--------------------------------------------------------------




void insert();

GLfloat red=1.0,green=0.0,blue=0.0;

void myReshape(int w,int h);
int i=0,x=-1,y=-1;
GLfloat angle=-20.0,xaxis=1.0,yaxis=1.0,zaxis=0.0;
char title[] = "3D Circular Queue algorithm ";

void shape()
{
glScaled(0.05,0.05,0.05);
glBegin(GL_QUADS);

 // Front face
    glColor3f(   red,  green, blue ); 
    glVertex2f(  1.0f,  1.0f );
    glVertex2f( -1.0f,  1.0f);
    glVertex2f( -1.0f, -1.0f );
    glVertex2f(  1.0f, -1.0f);   
   glEnd();
   }

void initGL() {
   glClearColor(0.0f, 0.0f,0.0f, 1.0f);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity();
glutSwapBuffers();
}




void menu(GLint option)
{
 switch(option)
    {
        case 1: x++;
        if(x>4)
{
char r1[]="Queue Overflow";
glColor3f(1.0,0.0,1.0);
glRasterPos3f(1.0,-1.5,0.2);
for(i=0;r1[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,r1[i]);
}
        if(x<=4)
{
char str3[]="inserted sucessfully";
glColor3f(0.0,1.0,1.0);
glRasterPos3f(-4.0,-1.2,0.2);
for(i=0;str3[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[i]);
}if(x>4)
						x=4;
               insert();
                break;
          
    }
 glutPostRedisplay();
}



void insert()
{

if(x==0 && y==0 ||x==1 && y==1 ||x==2 && y==2 ||x==3 && y==3 || x==4 && y==4)
{

char str2[]="Queue Empty";
glColor3f(1.0,0.0,1.0);
glRasterPos3f(1.0,-1.7,0.2);
for(i=0;str2[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
glutSwapBuffers();
}
 if(x==0 && y==-1)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');

red=1.0;
blue=green=0.0;

glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
shape();
glPopMatrix();
glutSwapBuffers();

}
if(x==1 && y==-1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');

green=0.0;blue=0.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
}
if(x==2 && y==-1)
{   
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
green=0.0;blue=0.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
}
if(x==3 && y==-1)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(0.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
red=1.0;blue=1.0;green=0.0;

  glPushMatrix();
  glTranslatef(0.5f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 


red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 

green=0.0;blue=0.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
}


 if(x==4 && y==-1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(0.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(1.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');

 red=0.2;blue=0.6;green=0.5;
glPushMatrix();
  glTranslatef(1.6f, 0.0f, -5.0f);  
  shape();
glPopMatrix();
glutSwapBuffers(); 

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 

red=1.0;blue=0.0;green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=0.0;green=1.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
red=1.0;blue=1.0;green=0.0;
 glPushMatrix();
  glTranslatef(0.5f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 


}
  
    if(x==1 && y==0)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
  red=0.0;blue=0.0;green=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

}
    
    if(x==2 && y==0)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
green=1.0;blue=0.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 

  }
  
      
    if(x==3 && y==0)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
 
red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
green=1.0;blue=0.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
}
if(x==4 && y==0)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(0.5,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
red=0.2;blue=0.5;green=0.6;

  glPushMatrix();
  glTranslatef(0.5f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 


red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 

green=1.0;blue=0.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 

  }
 
 // y=2
 
    
    if(x==2 && y==1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
  red=0.0;blue=1.0;green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();


  }
  
       
    if(x==3 && y==1)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
  green=0.0;blue=1.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
  }
if(x==4 && y==1)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-0.6,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');

red=0.2;blue=0.5;green=0.6;
glPushMatrix();
  glTranslatef(-0.6f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
green=0.0;blue=1.0;red=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=1.0;blue=1.0;green=0.0;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 

 }
 
 
 
       
    if(x==3 && y==2)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2); 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
red=1.0;blue=1.0;green=0.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

  }
 
       
    if(x==4 && y==2)
{
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2); 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-1.7,-0.85,0.2);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
green=0.0;blue=1.0;red=1.0;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();

red=0.2;blue=0.5;green=0.6;
glPushMatrix();
  
  glTranslatef(-1.7f, 0.0f, -5.0f);  
 shape();
glPopMatrix();
glutSwapBuffers(); 
 }
  if(x==4 && y==3)
{ 
glColor3f(1.0,1.0,1.0);
glRasterPos3f(-2.9,-0.85,0.2); 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');
green=0.6;blue=0.5;red=0.2;
glPushMatrix();
glTranslatef(-2.8f, 0.0, -5.0);
 shape();
glPopMatrix();
glutSwapBuffers();
}
}
void submenu(GLint option)
{
 switch(option)
    {
        case 1: red=1.0;green=0.0,blue=0.0;
        break;
        case 2: red=0.0;green=1.0,blue=0.0;
         break;
        case 3: red=0.0;green=0.0,blue=1.0;
         break;
        case 4: red=1.0;green=1.0,blue=1.0;
}
glutPostRedisplay();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{

	//glutReshapeFunc(myReshape);
	int id1= glutCreateMenu(submenu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("Blue",3);
	glutAddMenuEntry("White",4);
	glutCreateMenu(menu);
    glutAddMenuEntry("Insert",1);
    glutAddMenuEntry("Delete",2);
    glutAddSubMenu("Color",id1);
    
    
    glutKeyboardFunc(keyboard);
	glutDisplayFunc(display1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	//initGL();
	glFlush();


	}
}


void display1(void)
{
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
char str[]="Implementation Of Circular Queue";
char str1[]="FrontEnd                                                                                                                           Rear End";
glColor3f(1.0,1.0,0.0);
glRasterPos3f(-1.0,1.8,0.2);
/*for(i=0;str[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
glColor3f(0.0,0.0,1.0);
glRasterPos3f(-4.2,0.04,0.2);
for(i=0;str1[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[i]);
*/
drawstring(20, 90, "Implementation of Circular Queue");
drawstring(20, 90, "FrontEnd                                                                                                                           Rear End");
shape();
glutMouseFunc(mouse);

	glutKeyboardFunc(keyboard);
glFlush();

}




void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,10.0,-10.0);
	else
	glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}
//----------------------------------------------------------------copied--------------------------------------------------------------

void logicPage(){

	glColor3f( 0.0,1.0,0.8);
	setFont(GLUT_BITMAP_9_BY_15);
	drawstring(20, 90, "Press q for quit");
	drawstring(20, 70, "Press m for main menu");
	drawstring(20, 50, "Press ESC key to close the terminal");






	glutKeyboardFunc(keyboard);
	glFlush();
}



void mainMenu()
{


	glClearColor(0.5,0.0,0.3,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0, 1.0, 0.3);
	drawstring(270.0, 430.0, "CIRCULAR QUEUE");

	glColor3f(1.0, 1.0, 1.0);
	drawstring(100.0, 350.0, "It's an abstract datatype where elements are arranged in sequential manner but logically we assume it in circular format.");
	drawstring(50.0, 330.0, "It follows First In First Out(FIFO) method for insertion and deletion of elements.");
	
	glColor3f(0.2, 0.8, 0.0);
	drawstring(50.0,210.0,"START(s)");//label
	
	glColor3f(1.0, 0.8, 0.0);
	drawstring(50.0,170.0,"HELP(h)");//label
	
	glColor3f(1.0, 1.0, 0.7);
	drawstring(50.0,130.0,"QUIT(q)");//label

	glutKeyboardFunc(keyboard);
	glFlush();
	glutSwapBuffers();

}



void help() {
	glColor3f(0.0, 1.9, 0.0);
	drawstring(263, 415, "CIRCULAR QUEUE");

	glColor3f(1.5, 1.0, 1.0);
	drawstring(257, 375, "USER INSTRUCTIONS:");
	drawstring(255, 370, "____________________");

	glColor3f(1, 0.0, 0.5);
	drawstring(60, 348, "Keyboard Functions");

	glColor3f( 0.0,1.0,0.8);
	drawstring(60, 325, "Press ENTER to start");
	drawstring(60, 307, "Press 's' to start circular queue operations");
	drawstring(60, 289, "Press 'h' for help window");
	drawstring(60, 271, "Press 'q' for quit");
	drawstring(60, 253, "Press 'm' for main menu");
	drawstring(60, 230, "Press ESC key to close the terminal");
//	unsigned char* data = stbi_load(("C:\Users\vilas\Downloads\JOB.jpg").c_str(), &width, &height, &nrComponents, 4);
	glutKeyboardFunc(keyboard);
	glFlush();

}

void keyboard(unsigned char key, int a, int b) {
	if (key == 13) //ascii of enter is 13
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		mainMenu();

	}
	if (key == 'h') {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		help();
	}
	if (key == 'q' || key==27)//ascii of escape is 27
	{
		exit(0);
	}
	if(key=='s'){
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		//logicPage();
		display1();


	}
	if (key == 'm') {
		mainMenu();
	}
	
}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1800, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CIRCULAR QUEUE IMPLIMENTATION");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}