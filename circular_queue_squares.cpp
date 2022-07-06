#include<stdio.h>
#include<glut.h>
#include<string.h>
#include<math.h>

void firstDisplay();
void mouse(int btn, int state, int x, int y);
void mouse1(int btn, int state, int x, int y);
void insert();
void delt();
void about(); 
void myReshape(int w, int h);

GLfloat red = 1.0, green = 0.0, blue = 0.0;
int size=0;
int i = 0, y = -1, x = -1;
int count=0;
char title[] = "Circular Queue Implementation ";
int o, t, tt, f, ff;
void* currentfont;
int flag = 0;

int q[5];

void setFont(void* font)
{
    currentfont = font;
}

void cube() {
/*    glBegin(GL_QUADS);
    glColor3f(red,green,blue);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glFlush();
	*/
	   glBegin(GL_QUADS);
    glColor3f(red,green,blue);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glFlush();
}

void drawstring(GLfloat x, GLfloat y, const char* string)
{
	const char* c;

	glRasterPos2f(x, y);
	for (c = string;*c != '\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}
void initGL() {
    // glClearColor(0.2f, 0.2f,0.2f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSwapBuffers();
}
void help();
void submenu(GLint option)
{
    switch (option)
    {
    case 1: red = 1.0;green = 0.0;blue = 0.0;
        break;
    case 2: red = 0.0;green = 1.0;blue = 0.0;
        break;
    case 3: red = 0.0;green = 0.0;blue = 1.0;
        break;
    case 4: red = 1.0;green = 1.0;blue = 0.4;
    }
    glutPostRedisplay();
	glFlush();
	insert();
}

void menu(GLint option)
{
	if(count > size){
	count=0;
	}
    switch (option)
    {
    case 1:  if (y > size)
    {
        char r1[] = "Queue Overflow";
        glColor3f(1.0, 0.0, 0.5);
        glRasterPos3f(1.4, 4.5, 0.2);
        for (i = 0;r1[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
        glutSwapBuffers();
    }


          if (y <= size)
          {
			  ++count;
              char str3[] = "Inserted...";
              glColor3f(0.1, 1.0, 1.0);
              glRasterPos3f(-0.5, -0.8, 0.2);
              for (i = 0;str3[i] != '\0';i++)
                  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
          }
          if (y == -1 && x == -1) {
              x = y = 0;
              insert();
          }
 		else if ((y + 1) % size == x) {
			count=size;
			char r1[] = "Queue is full";
			glColor3f(1.0, 0.0, 1.0);
			glRasterPos3f(2.4, 0.5, 0.2);
			for (i = 0; r1[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
		}
          else {
              y = (y + 1) % size;
              insert();
          }
          break;

    case 2:
		--count;
        delt();
        break;


    case 3:
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("Help");

        glutDisplayFunc(help);
        glutReshapeFunc(myReshape);
        glutPostRedisplay();
        break;

    }
    glutPostRedisplay();
}

void insert()
{

	
	
		
    if (y == -1 && x == -1)
    {
        char str2[] = "Queue Underflow";
        glColor3f(1.0, 0.0, 1.0);
        glRasterPos3f(2.4, 0.5, 0.2);
        for (i = 0;str2[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);

        glutSwapBuffers();
    }
    if ((y + 1) % 5 == x) {
        char r1[] = "Queue is Overflow!!!";
        glColor3f(1.0, 0.0, 1.0);
        glRasterPos3f(2.4, 0.5, 0.2);
        for (i = 0;r1[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
    }
    if (y == 0 && x == 0)
    {
		glColor3f(0.0,0.0,0.0);

		/*char inp;
		printf("Enter an element");
		gets("%s",&inp);*/

        drawstring(-2.9, -0.2,"1");

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (y == 1 && x == 0)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "1");
        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(-1.7, -0.2, "2");
        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (y == 2 && x == 0)
    {
      glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "1");
        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
		 
        drawstring(-1.7, -0.2, "2");
        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(-0.6, -0.2, "3");
        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (y == 3 && x == 0)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "1");
        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glColor3f(0.0,0.0,0.0);
        drawstring(-1.7, -0.2, "2");
        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


       glColor3f(0.0,0.0,0.0);
        drawstring(-0.6, -0.2,"3" );
        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glColor3f(0.0,0.0,0.0);
        drawstring(0.5, -0.2, "4");
        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (y == 4 && x == 0)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "1");
        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(-1.7, -0.2, "2");
        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(-0.6, -0.2, "3");
        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(0.5, -0.2, "4");
        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(1.5, -0.2, "5");
        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 4 && x == 1)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "2");
        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(-1.7, -0.2, "3");
        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(-0.6, -0.2, "4");
        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        drawstring(0.5, -0.2, "5");
       // red = 1.0;blue = 1.0; green = 0.0;

        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 4 && x == 2)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "3");
        drawstring(-1.7, -0.2, "4");
        drawstring(-0.6, -0.2, "5");


        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 4 && x == 3)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "4");
        drawstring(-1.7, -0.2, "5");

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 4 && x == 4)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "5");
        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 3 && x == 1)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "2");
        drawstring(-1.7, -0.2, "3");
        drawstring(-0.6, -0.2, "4");

        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 3 && x == 2)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "3");
        drawstring(-1.7, -0.2, "4");

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 3 && x == 3)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "4");
        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 2 && x == 1)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "2");
        drawstring(-1.7, -0.2, "3");
        //red = 0.0;blue = -1.5; green = 1.0;

        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();

    }

    if (y == 2 && x == 2)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "3");
        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 1 && x == 1)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "2");

        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 0 && x == 1)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "2");
        drawstring(-1.7, -0.2, "3");
        drawstring(-0.6, -0.2, "4");
        drawstring(0.5, -0.2, "5");
        drawstring(1.5, -0.2, "6");

        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 0 && x == 2)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-1.7, -0.2, "4");
        drawstring(-0.6, -0.2, "5");
        drawstring(0.5, -0.2, "6");

       // blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (y == 0 && x == 3)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "4");
        drawstring(-1.7, -0.2, "5");
        drawstring(-0.6, -0.2, "6");

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

       // red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 1.0;blue = green = 0.0;

        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
        glutSwapBuffers();
    }

    if (y == 0 && x == 4)
    {
       glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "5");
        drawstring(-1.7, -0.2, "6");

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
        glutSwapBuffers();
    }

    if (y == 1 && x == 2)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "3");
        drawstring(-1.7, -0.2, "4");
        drawstring(-0.6, -0.2, "5");
        drawstring(0.5, -0.2, "6");
        drawstring(1.5, -0.2, "7");

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();

    }

    if (y == 1 && x == 3)
    {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "4");
        drawstring(-1.7, -0.2, "5");
        drawstring(-0.6, -0.2, "6");
        drawstring(0.5, -0.2, "7");

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }


    if (y == 1 && x == 4)
    {
     glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "5");
        drawstring(-1.7, -0.2,"6");
        drawstring(-0.6, -0.2, "7");

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
        glutSwapBuffers();
    }

    if (y == 2 && x == 3)
    {
        glColor3f(0.0,0.0,0.0);

        drawstring(-2.9, -0.2,"4");
        drawstring(-1.7, -0.2, "5");
        drawstring(-0.6, -0.2, "6");
        drawstring(0.5, -0.2, "7");
        drawstring(1.5, -0.2, "8");

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

       // red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glutSwapBuffers();
    }

    if (y == 2 && x == 4)
   {
        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "5");
        drawstring(-1.7, -0.2,"6");
        drawstring(-0.6, -0.2, "7");
        drawstring(0.5, -0.2, "8");
        drawstring(1.5, -0.2, "9");

        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.9f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (y == 3 && x == 4)
    {

        glColor3f(0.0,0.0,0.0);
        drawstring(-2.9, -0.2, "5");
        drawstring(-1.7, -0.2,"6");
        drawstring(-0.6, -0.2, "7");
        drawstring(0.5, -0.2, "8");
        drawstring(1.5, -0.2, "9");
 
        //red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 1.0;blue = green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        //blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5, -5.0);
        cube();
        glPopMatrix();

        //red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glutSwapBuffers();
    }
}
void delt()
{
    if (x == -1 && y == -1) {
        printf("Queue underflow \n");
    }
    else if (x == y) {
        x = y = -1;
        char str3[] = "Deleted sucessfully";
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos3f(-0.5, -0.8, 0.2);
        for (i = 0;str3[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
        insert();
    }
    else {
        x = (x + 1) % 5;
        char str3[] = "Deleted sucessfully";
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos3f(-0.5, -0.8, 0.2);
        for (i = 0;str3[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
        insert();
    }
}

void key(unsigned char key, int a, int b)
{
if(count > size){
	count=0;
	}

	if (key == 8)
	{
		--count;
		delt();
		if (x < 5 && x <= y)
		{
			printf("%d Deleted sucessfully\n", x + 1);
		}
	}

	if (key == 13)
	{

		if (count == size)
		{
			char r1[] = "Queue is full";
			glColor3f(1.0, 0.0, 1.0);
			glRasterPos3f(2.4, 0.5, 0.2);
			for (i = 0; r1[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
			glutSwapBuffers();
		}
		else{

		if (y <= 4)
		{
			char str3[] = "Inserted sucessfully";
			glColor3f(0.0, 1.0, 1.0);
			glRasterPos3f(-1.0, -0.8, 0.2);
			for (i = 0; str3[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
			++count;
		}
		if (y == -1 && x == -1) {
			x = y = 0;
			insert();
		}

		else if ((y + 1) % size == x) {
			count=size;
			char r1[] = "Queue is full";
			glColor3f(1.0, 0.0, 1.0);
			glRasterPos3f(2.4, 0.5, 0.2);
			for (i = 0; r1[i] != '\0'; i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
		}
		else {
			y = (y + 1) % size;
			insert();
		}
	}
}
	if (key == 'h' || key == 'H' || key == 'm') {
		int id = glutGetWindow();
		glutDestroyWindow(id);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1600, 800);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Help");
		glutDisplayFunc(help);
		glutReshapeFunc(myReshape);
		glutPostRedisplay();
	}
	if (key == 'B' || key == 'b'){
		int id = glutGetWindow();
		glutDestroyWindow(id);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1600, 800);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Queue operation");

		glutDisplayFunc(about);
		glutReshapeFunc(myReshape);

	}

	if (key == 's' || key == 'S') {

		int id = glutGetWindow();
		glutDestroyWindow(id);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(1600, 800);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Simulation Of Circular Queue");

		//glutKeyboardFunc(key);
		glutDisplayFunc(firstDisplay);
		glutMouseFunc(mouse1);
		glutReshapeFunc(myReshape);
		glutSwapBuffers();

		//initGL();
		//glFlush();
	}

	if (key == 27 || key == 'Q' || key == 'q'){
		exit(0);
	}

	glutPostRedisplay();
}

void about(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	//glLineWidth(3);
	glColor3f(1.0, 1.0, 0.0);
	drawstring(-1.5, 1.5, "------| CIRCULAR QUEUE OPERATION |-------");

	glColor3f(0.1, 1.0, 1.0);
	drawstring(-3.0, 1.2, "(1) A circular queue is the extended version of a regular queue where the last element is connected to the first element.");
	drawstring(-3.0, 1.0, "(2) It's an abstract datatype where elements are arranged in sequential manner but logically we assume it in circular format.");
	drawstring(-3.0, 0.8, "(3) It follows First In First Out(FIFO) method for insertion and deletion of elements.");
	drawstring(-3.0, 0.6, "(4) Thus forming a circle-like structure. Circular queue representation.Basically the circular queue solves the major limitation");
	drawstring(-3.0, 0.4, "  of the normal queue.");

	glColor3f(1, 0.0, 0.3);
	drawstring(-3.2, -1.0, "TO START,PRESS ( S/s )");

	glColor3f(0.5, 1.0, 0.5);
	drawstring(-3.2, -1.3, "FOR HELP,PRESS ( H/h )");

	glColor3f(0.8, .2, 0.8);
	drawstring(-3.2, -1.6, "TO QUIT,PRESS ( Q/q )");

	glutKeyboardFunc(key);
	glFlush();
	glutSwapBuffers();
}

void help() {
   //-*-*-*---------------------------------------------HELP WINDOW---------------------------------------

	glClearColor(1.0, 1.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.186, 0.0, 1.153);
	drawstring(-1.5, 1.7, "-*-*-*-*-*-*-| WORKING FLOW CHART |*-*-*-*-*-*-*-");

	//-----------------------------------------FLOW CHART START-------------------------------------------
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.9, 1.3);
	glVertex2f(-1.9, 1.3);
	glVertex2f(-1.9, 1.1);
	glVertex2f(-0.9, 1.1);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(-1.6, 1.15, "START->");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-0.9, 1.2);
	glVertex2f(-0.6, 1.2);
	glEnd();


	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, 1.3);
	glVertex2f(0.6, 1.3);
	glVertex2f(0.6, 1.1);
	glVertex2f(-0.6, 1.1);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(-0.5, 1.15, "WELCOME PAGE");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,1.1);
	glVertex2f(0.0,0.9);
	glEnd();


	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, 0.9);
	glVertex2f(0.6, 0.9);
	glVertex2f(0.6, 0.7);
	glVertex2f(-0.6, 0.7);
	glEnd();

	glColor3f(1, 0.0, 0.3);
	drawstring(-0.4, 0.75, "ABOUT PAGE");
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex2f(0.0, 0.7);
	glVertex2f(0.0, 0.5);
	glEnd();


	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, 0.5);
	glVertex2f(0.6, 0.5);
	glVertex2f(0.6, 0.3);
	glVertex2f(-0.6, 0.3);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(-0.4, 0.35, "SIMULATION");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.3);
	glVertex2f(0.0, 0.1);
	glEnd();


	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.9, 0.5);
	glVertex2f(-1.9, 0.5);
	glVertex2f(-1.9, 0.3);
	glVertex2f(-0.9, 0.3);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(-1.5, 0.35, "HELP");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.6);
	glVertex2f(-1.4, 0.6);
	glVertex2f(-1.4, 0.6);
	glVertex2f(-1.4, 0.5);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.9, 0.5);
	glVertex2f(1.9, 0.5);
	glVertex2f(1.9, 0.3);
	glVertex2f(0.9, 0.3);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(1.3, 0.35, "EXIT");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.6);
	glVertex2f(1.4, 0.6);
	glVertex2f(1.4, 0.6);
	glVertex2f(1.4, 0.5);
	glEnd();


	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, 0.1);
	glVertex2f(0.6, 0.1);
	glVertex2f(0.6, -0.6);
	glVertex2f(-0.6, -0.6);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(-0.5, 0.0, "1. INSERT");
	drawstring(-0.5, -0.17, "2. DELETE");
	drawstring(-0.5, -0.37, "3. CHANGE COLOR");
	drawstring(-0.5, -0.5, "4. HELP");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0, -0.6);
	glVertex2f(0.0, -0.8);
	glEnd();


	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.6, -0.8);
	glVertex2f(0.6, -0.8);
	glVertex2f(0.6, -1.0);
	glVertex2f(-0.6, -1.0);
	glEnd();
	glColor3f(1, 0.0, 0.3);
	drawstring(-0.3, -0.95, "EXIT");
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.6, -0.9);
	glVertex2f(1.4, -0.9);
	glVertex2f(1.4, -0.9);
	glVertex2f(1.4, 0.3);
	glEnd();
	//-----------------------------------------FLOW CHART END-------------------------------------------
	glColor3f(1, 0.0, 0.3);
	drawstring(-3.2, -1.2, "TO START,PRESS ( S/s )");

	glColor3f(1, 0.0, 0.3);
	drawstring(1.0, -1.5, "TO GO BACK,PRESS ( B/b )");

	glColor3f(0.0, 0.0, 0.0);
	drawstring(-3.2, -1.4, "FOR HELP,PRESS ( H/h )");

	glColor3f(0.8, .2, 0.8);
	drawstring(-3.2, -1.6, "TO QUIT,PRESS ( Q/q )");

	glutKeyboardFunc(key);

	glFlush();
	glutSwapBuffers();


}

void firstDisplay(void)
{
    glLoadIdentity();
	//glClearColor(1.0,0.2,0.4,1.0);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//background
	glColor3f(1.0,0.2,0.4);
	glBegin(GL_POLYGON);
    glVertex2f(-3.7f, -3.5f);
	glColor3f(0.0,0.3,0.6);
    glVertex2f(3.6f, -3.5f);
    glVertex2f(3.6f, 3.5f);
    glVertex2f(-3.7f, 3.5f);
    glEnd();
	glFlush();


    glColor3f(0.0, 1.0, 0.0);
    drawstring(-3.4, -1.0,  "CIRCULAR QUEUE OPERTATIONS:");
    glColor3f(0.9, 0.9, 0.3);
    drawstring(-3.4, -1.2,  "1. Enqueue - Press ENTER");
    drawstring(-3.4, -1.4, "2. Dequeue - Press Backspace");
    drawstring(1.4, -1.2, "3. About - Press b/B");
    drawstring(1.4, -1.4, "4. Help - Press h/H");
    glFlush();

	glutKeyboardFunc(key);

		int id1 = glutCreateMenu(submenu);
        glutAddMenuEntry("Red", 1);
        glutAddMenuEntry("Green", 2);
        glutAddMenuEntry("Blue", 3);
        glutAddMenuEntry("Other", 4);
        
		glutCreateMenu(menu);
		glutAddMenuEntry("Insert", 1);
        glutAddMenuEntry("Delete", 2);
        glutAddMenuEntry("Help", 3);
		glutAddSubMenu("Color Of Cube", id1);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(mouse);
}


void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		int id = glutGetWindow();
		glutDestroyWindow(id);

        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("About Circular Queue");

        glutKeyboardFunc(key);
        //glutDisplayFunc(firstDisplay);
		glutDisplayFunc(about);
        glutReshapeFunc(myReshape);

        //initGL();
        //glFlush();
    }
}

void mouse1(int btn, int state, int x, int y){
	    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {


        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("About Circular Queue");

        glutKeyboardFunc(key);
        //glutDisplayFunc(firstDisplay);
        glutReshapeFunc(myReshape);

		
	
        //initGL();
        glFlush();
    }
}

void display(void)
{
glLineWidth(5);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT);

glPushMatrix(); 
char str[]="SDM Institute Of Technology,Ujire";
glColor3f(1.0,1.0,0.0);
glTranslatef(30.0,360.0,0.0);
glScaled(0.1,0.2,0.0);

for(i=0;str[i]!='\0';i++)
glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
glPopMatrix();

glPushMatrix(); 

glLineWidth(3);
drawstring(130,340,"Department of Computer Science & Engineering");
glColor3f(0.5, 1, 1.0);
	drawstring(130, 320, "A COMPUTER GRAPHICS MINI PROJECT ON");
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(9);
	drawstring(120, 300, "------| CIRCULAR QUEUE OPERATIONS |-------");
	glLineWidth(4);


 glPushMatrix(); 

	glColor3f(1, 0.0, 0.3);
	drawstring(25, 180, "SUBMITTED BY:");
	glColor3f(0.5, 1.0, 0.5);

	drawstring(25, 150, "Mr. Vilas Hegde(4SU19CS111)");
	drawstring(25, 130, "Mr. Abdul Imad(4SU20CS400)");
	drawstring(25, 110, "Ms. Shruti(4SU20CS407)");
	drawstring(25, 90, "Mr. Sunil Naik(4SU20CS408)");
	
	glColor3f(1, 0.0, 0.3);
	drawstring(313, 150, "GUIDED BY:");
	glColor3f(0.5, 1.0, 0.5);
	drawstring(313, 130, "Mr. Arjun K");
	glPopMatrix();

	glColor3f(0.8, .2, 0.8);
	drawstring(313, 60, "Click to Continue -->");

	glPopMatrix();

	glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutSwapBuffers();
    glFlush();

}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, 10.0, -10.0);
    else
        glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    printf("Circular Queue\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1800, 1000);
    glutInitWindowPosition(0, 0);

	printf("Enter the Queue size : \n");
	scanf("%d", &size);

	while(1){
		if(size<6){
		break;
		}
		else{
	printf("Enter the Queue size <= 5: \n");
	scanf("%d", &size);
		}
	}

    glutCreateWindow(title);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
