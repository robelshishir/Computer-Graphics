#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(20,20,0);
    glVertex3f(80,20,0);
    glVertex3f(80,80,0);
    glVertex3f(20,80,0);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(40,40,0);
    glVertex3f(60,40,0);
    glVertex3f(60,60,0);
    glVertex3f(40,60,0);
    glEnd();

    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(20,80,0);
    glVertex3f(80,80,0);
    glVertex3f(50,90,0);
    glEnd();

    glFlush();
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
    glutCreateWindow ("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
