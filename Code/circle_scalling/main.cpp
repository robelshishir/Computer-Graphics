#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

GLint i;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-15,15,-15,15,-15,5);
}
void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    circle(3);
    glColor3f(1,0,0); /// red color
    glPushMatrix();
    glTranslatef(8,8,0); /// translate red circle
    circle(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,0); /// green color
    glScaled(0.5, 0.5, 0.5); /// scaling of green color
    glTranslatef(10,10,0); /// translate green (scaled) circle
    circle(3);

    glFlush();
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle scaling");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
