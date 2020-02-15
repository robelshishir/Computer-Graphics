#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
//lest house
glColor3f (0.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (40, 12, 0.0);
glVertex3f (120, 12, 0.0);
glVertex3f (120, 45, 0.0);
glVertex3f (40, 45, 0.0);
glEnd();

//lest house floor shed
glColor3f (1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (30, 45, 0.0);
glVertex3f (120, 45, 0.0);
glVertex3f (120, 65, 0.0);
glVertex3f (50, 65, 0.0);
glEnd();

//left house window left+down
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (50, 20, 0.0);
glVertex3f (75, 20, 0.0);
glVertex3f (75, 30, 0.0);
glVertex3f (50, 30, 0.0);
glEnd();


//left house window left+up
glColor3f (1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (50, 30, 0.0);
glVertex3f (75, 30, 0.0);
glVertex3f (75, 40, 0.0);
glVertex3f (50, 40, 0.0);
glEnd();


//left house window right+down
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (85, 20, 0.0);
glVertex3f (110, 20, 0.0);
glVertex3f (110, 30, 0.0);
glVertex3f (85, 30, 0.0);
glEnd();


//left house window left+up
glColor3f (1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (85, 30, 0.0);
glVertex3f (110, 30, 0.0);
glVertex3f (110, 40, 0.0);
glVertex3f (85, 40, 0.0);
glEnd();





//main house
glColor3f (0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (120, 10, 0.0);
glVertex3f (180, 10, 0.0);
glVertex3f (180, 50, 0.0);
glVertex3f (120, 50, 0.0);
glEnd();

//main house door
glColor3f (1.0, 0.25, 1.0);
glBegin(GL_POLYGON);
glVertex3f (130, 10, 0.0);
glVertex3f (170, 10, 0.0);
glVertex3f (170, 40, 0.0);
glVertex3f (130, 40, 0.0);
glEnd();

//main house 1st floor shed
glColor3f (1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (110, 50, 0.0);
glVertex3f (190, 50, 0.0);
glVertex3f (180, 60, 0.0);
glVertex3f (120, 60, 0.0);
glEnd();

//main house 2
glColor3f (0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f (120, 60, 0.0);
glVertex3f (180, 60, 0.0);
glVertex3f (180, 80, 0.0);
glVertex3f (120, 80, 0.0);
glEnd();

////main house 2nd floor shed
glColor3f (1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f (110, 80, 0.0);
glVertex3f (190, 80, 0.0);
glVertex3f (150, 100, 0.0);
glEnd();


/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 200.0, 0.0, 120.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
