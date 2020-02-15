#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (1.0, 0.25, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (20, 20, 0.0);
    glVertex3f (80, 20, 0.0);
    glVertex3f (80, 80, 0.0);
    glVertex3f (20, 80, 0.0);
    glEnd();


    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (40, 30, 0.0);
    glVertex3f (60, 30, 0.0);
    glVertex3f (60, 40, 0.0);
    glVertex3f (40, 40, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (30, 50, 0.0);
    glVertex3f (45, 50, 0.0);
    glVertex3f (45, 60, 0.0);
    glVertex3f (30, 60, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (55, 50, 0.0);
    glVertex3f (70, 50, 0.0);
    glVertex3f (70, 60, 0.0);
    glVertex3f (55, 60, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (20, 80, 0.0);
    glVertex3f (80, 80, 0.0);
    glVertex3f (50, 90, 0.0);
    glEnd();


    glFlush ();
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("house");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
