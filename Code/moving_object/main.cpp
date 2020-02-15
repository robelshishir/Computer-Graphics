#include<windows.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

float p=-10.0;
int state = 1;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(p,3);
    glVertex2f(p+3,3);
    glVertex2f(p+3,-3);
    glVertex2f(p,-3);
    glEnd();

	glFlush();
}

void timer(int)
{
    switch(state){   // Left to right & Right to left
        case 1:
            if(p<7)
                p = p + 0.10;
            else
                state = -1;
                break;
        case -1:
            if(p>-10)
                p =p - 0.10;
            else
                state = 1;
                break;
      }
    glutPostRedisplay(); // To redraw the object in the display
    glutTimerFunc(1000/60,timer,0);
}

void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0);
	glOrtho(-10,10,-10,10,-10,10);
}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("moving_object");
	init();
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
	glutMainLoop();
	return 0;
}
