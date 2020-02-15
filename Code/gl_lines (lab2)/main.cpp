/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

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
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (20, 10);
glVertex2f (80, 10);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (80, 80);
glVertex2f (80, 10);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (20, 80);
glVertex2f (80, 80);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (20, 10);
glVertex2f (20, 80);
glEnd();




glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (40, 20);
glVertex2f (60, 20);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (60, 60);
glVertex2f (60, 20);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (60, 60);
glVertex2f (40, 60);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (40, 20);
glVertex2f (40, 60);
glEnd();




glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (25, 50);
glVertex2f (35, 50);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (35, 50);
glVertex2f (35, 70);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (25, 70);
glVertex2f (35, 70);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (25, 50);
glVertex2f (25, 70);
glEnd();



glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (65, 50);
glVertex2f (75, 50);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (75, 50);
glVertex2f (75, 70);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (65, 70);
glVertex2f (75, 70);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (65, 50);
glVertex2f (65, 70);
glEnd();




glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (20, 80);
glVertex2f (50, 90);
glEnd();

glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f (80, 80);
glVertex2f (50, 90);
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
glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
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
