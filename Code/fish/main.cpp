#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

//GLfloat cx=0;
int i;

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<100;i++)

    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}

void fish()
{
    glBegin(GL_POLYGON);
    //glColor3f(1,0,0);

    glVertex2f(20,40);
    glVertex2f(55,20);
    glVertex2f(45,30);
    glVertex2f(60,40);
    glVertex2f(75,30);
    glVertex2f(75,45);

    glVertex2f(60,40);
    glVertex2f(45,45);
    glVertex2f(55,60);
    glEnd();

    glFlush();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);

    fish();
    glColor3f(0,1,0);
    circle(2,2,28,40);

    glPushMatrix();
    glTranslatef(25,40,0);
    glColor3f(1,0,0);
    fish();
    glColor3f(0,1,0);
    circle(2,2,28,40);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(55,70,0);
    glColor3f(0,0,1);
    fish();
    glColor3f(0,1,0);
    circle(2,2,28,40);
    glPopMatrix();



    glFlush();

}

void init(void)
{
    glColor3f(1,1,1);
    glOrtho(0,200,0,160, -1.0, 1.0);
}

int main()
{
    printf(">><< Press N for nightmood>><< Press D for day mood >><<\n\n");
    printf("Click Mouse Left/Right Button for cloud movement\n\n");
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize (1350, 690);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (50, 50);
    glutCreateWindow("Fish");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
