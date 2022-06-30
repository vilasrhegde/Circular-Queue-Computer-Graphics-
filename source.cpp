#include<stdlib.h>
#include<stdio.h>
#include<glut.h>
#include<string.h>

void keyboard(unsigned char key, int a, int b);
void mainMenu();
void drawstring(GLfloat x, GLfloat y, const char* string);
void* currentfont;



void setFont(void* font)
{
	currentfont = font;
}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glLineWidth(7);
	glColor3f(0.65, 0.65, 0.0);
	gluOrtho2D(0.1, 640.0, 0.0, 480.1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawstring(GLfloat x, GLfloat y, const char* string)
{
	const char* c;
	glRasterPos2f(x, y);
	for (c = string;
		*c != '\0';
		c++)
	{
		glutBitmapCharacter(currentfont, *c);
	}
}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	drawstring(225, 400, "SDM INSTIUTE OF TECHNOLOGY, UJIRE");
	glColor3f(0.5, 1, 1.0);
	drawstring(225, 343, "A COMPUTER GRAPHICS MINI PROJECT ON");
	glColor3f(1.0, 1.0, 1.0);
	drawstring(213, 313, "------| CIRCULAR QUEUE OPERATIONS |-------");

	glColor3f(1, 0.0, 0.3);
	drawstring(45, 210, "SUBMITTED BY:");
	glColor3f(0.5, 1.0, 0.5);
	drawstring(45, 150, "Mr. Abdul Imad(4SU20CS400)");
	drawstring(45, 130, "Mr. Sunil Naik(4SU20CS408)");
	drawstring(45, 110, "Ms. Shruti(4SU20CS407)");
	drawstring(45, 170, "Mr. Vilas Hegde(4SU19CS111)");

	
	glColor3f(1, 0.0, 0.3);
	drawstring(513, 195, "GUIDED BY:");
	glColor3f(0.5, 1.0, 0.5);
	drawstring(513, 170, "Prof.Arjun K");
	
	glColor3f(0.0, 0.8, 0.9);
	drawstring(470, 90, "PRESS ENTER TO START");
	glFlush();
}
//glutSwapBuffers();

//to display sorted array


void mainMenu()
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0, 1.0, 0.3);
	drawstring(270.0, 430.0, "CIRCULAR QUEUE");

	glColor3f(1.0, 1.0, 1.0);
	drawstring(100.0, 350.0, "It's an abstract datatype where elements are arranged in sequential manner but logically we assume it in circular format");
	drawstring(50.0, 330.0, "It follows “First In First Out”(FIFO) method for insertion and deletion of elements.");
	
	glColor3f(0.2, 0.8, 0.0);
	drawstring(50.0,210.0,"START(s)");//label
	
	glColor3f(1.0, 0.8, 0.0);
	drawstring(50.0,170.0,"HELP(h)");//label
	
	glColor3f(1.0, 0.0, 0.2);
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

	glutKeyboardFunc(keyboard);
	glFlush();

}

void keyboard(unsigned char key, int a, int b) {
	if (key == 13) {

		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		mainMenu();

	}
	if (key == 'h') {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		help();
	}
	if (key == 'n') {
		glClear(GL_COLOR_BUFFER_BIT);

	}
	if (key == 'q' || key==27)
	{
		exit(0);
	}
	if (key == 'm') {
		mainMenu();
	}
	
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
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
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}