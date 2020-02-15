#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

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


    /* door*/

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


    /* Left window*/

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

    /* Right window*/

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


    /* trivuj*/

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



    /* Polygon*/


    /* shape */

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (120, 10, 0.0);
    glVertex3f (180, 10, 0.0);
    glVertex3f (180, 80, 0.0);
    glVertex3f (120, 80, 0.0);
    glEnd();


    /* door*/

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (140, 20, 0.0);
    glVertex3f (160, 20, 0.0);
    glVertex3f (160, 60, 0.0);
    glVertex3f (140, 60, 0.0);
    glEnd();


    /* Left window*/

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (125, 50, 0.0);
    glVertex3f (135, 50, 0.0);
    glVertex3f (135, 70, 0.0);
    glVertex3f (125, 70, 0.0);
    glEnd();


    /* Right window*/

    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (165, 50, 0.0);
    glVertex3f (175, 50, 0.0);
    glVertex3f (175, 70, 0.0);
    glVertex3f (165, 70, 0.0);
    glEnd();



    /* trivuj*/

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (120, 80, 0.0);
    glVertex3f (180, 80, 0.0);
    glVertex3f (150, 90, 0.0);
    glEnd();

    glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 250.0, 0.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("lines");

    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
