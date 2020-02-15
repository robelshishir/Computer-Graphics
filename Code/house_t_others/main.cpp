#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx,cy);

    for(int i=0;i<=1000;i++)
    {
        float angle = 2 * 3.1416f * i/1000;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void tri()
{
    //glColor3f (0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f (45, 10, 0.0);
    glVertex3f (65, 10, 0.0);
    glVertex3f (55, 30, 0.0);

    glEnd();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 0, 0.0);
    glVertex3f (100, 0, 0.0);
    glVertex3f (100, 100, 0.0);
    glVertex3f (0,100, 0.0);
    glEnd();

    glColor3f (0.0, 1.0, 0.0);
    circle(60,50,50,0);
    glColor3f (1.0, 1.0, 0.0);
    circle(10,10,75,20);
    glColor3f (1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (10, 10, 0.0);
    glVertex3f (20, 10, 0.0);
    glVertex3f (20, 20, 0.0);
    glVertex3f (10, 20, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (25, 10, 0.0);
    glVertex3f (40, 10, 0.0);
    glVertex3f (40, 20, 0.0);
    glVertex3f (25, 20, 0.0);
    glEnd();

    tri();

    glColor3f (1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (60, 45, 0.0);
    glVertex3f (90, 45, 0.0);
    glVertex3f (90, 70, 0.0);
    glVertex3f (60, 70, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (55, 70, 0.0);
    glVertex3f (95, 70, 0.0);
    glVertex3f (75, 80, 0.0);
    glEnd();

    glColor3f (1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (65, 60, 0.0);
    glVertex3f (70, 60, 0.0);
    glVertex3f (70, 65, 0.0);
    glVertex3f (65, 65, 0.0);
    glEnd();

    glColor3f (1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (80, 60, 0.0);
    glVertex3f (85, 60, 0.0);
    glVertex3f (85, 65, 0.0);
    glVertex3f (80, 65, 0.0);
    glEnd();

    glColor3f (1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (73, 48, 0.0);
    glVertex3f (78, 48, 0.0);
    glVertex3f (78, 60, 0.0);
    glVertex3f (73, 60, 0.0);
    glEnd();

    glColor3f (1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (40, 30, 0.0);
    glVertex3f (40, 70, 0.0);
    glVertex3f (50, 70, 0.0);
    glVertex3f (50, 40, 0.0);
    glVertex3f (58, 40, 0.0);
    glVertex3f (58, 30, 0.0);
    //glVertex3f (40, 30, 0.0);
    glEnd();

    glColor3f (1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f (15, 30, 0.0);
    glVertex3f (25, 30, 0.0);
    glVertex3f (25, 60, 0.0);
    glVertex3f (15, 60, 0.0);
    glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glPushMatrix();

    glTranslatef(-35,50,0);

    tri();

    glPopMatrix();

    glColor3f (0.0, 1.0, 0.0);
    glPushMatrix();

    glTranslatef(-35,55,0);
    tri();
    glPopMatrix();

    glColor3f (1.0, 1.0, 1.0);//cloud
    circle(3,3,80,85);

    circle(5,3,85,85);

    circle(3,3,90,85);

    circle(3,3,40,85);

    circle(5,5,45,88);

    circle(3,3,50,85);

    glColor3f (1.0, 1.0, 0);//sun
    circle(5,5,10,85);

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
glutCreateWindow ("house_t_others");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
