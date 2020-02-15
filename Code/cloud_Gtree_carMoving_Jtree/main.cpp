#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i;
GLfloat cx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;

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

void bus()
{
    // buss.....................................................

    //body lower portion
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.52, 0.2, 0);
    glVertex3f(-0.9, 0.2, 0);
    glVertex3f(-0.87, 0.5, 0);
    glVertex3f(-0.52, 0.5, 0);
    glEnd();

    //body lower  front portion
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.43, 0.2, 0);
    glVertex3f(-0.52, 0.2, 0);
    glVertex3f(-0.52, 0.5, 0);
    glVertex3f(-0.46, 0.45, 0);
    glEnd();

    //body upper portion
    glColor3f(1.0, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.53, 0.5, 0);
    glVertex3f(-0.83, 0.5, 0);
    glVertex3f(-0.77, 0.8, 0);
    glVertex3f(-0.56, 0.75, 0);
    glEnd();

    // line middle lower
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.65, 0.2, 0);
    glVertex3f(-0.65, 0.5, 0);
    glEnd();

    // line middle upper
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.65, 0.5, 0);
    glVertex3f(-0.68, 0.79, 0);
    glEnd();

    // line left lower
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.75, 0.2, 0);
    glVertex3f(-0.75, 0.5, 0);
    glEnd();

    // line left upper
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.75, 0.5, 0);
    glVertex3f(-0.77, 0.8, 0);
    glEnd();

    // line right lower
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.55, 0.2, 0);
    glVertex3f(-0.55, 0.5, 0);
    glEnd();

    // line right upper
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.55, 0.5, 0);
    glVertex3f(-0.58, 0.77, 0);
    glEnd();

    // body lower portion (dot) right
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.6, 0.4, 0);
    glVertex3f(-0.62, 0.4, 0);
    glEnd();

    // body lower portion (dot) left
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-0.7, 0.4, 0);
    glVertex3f(-0.72, 0.4, 0);
    glEnd();

    // chaka left (black)
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-.78, .2, 0);
    circle(0.06);
    glPopMatrix();

    // chaka right (black)
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-.5, .2, 0);
    circle(0.06);
    glPopMatrix();

    // chaka right (white)
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(-.5, .2, 0);
    circle(0.02);
    glPopMatrix();

    // chaka left (white)
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(-.78, .2, 0);
    circle(0.02);
    glPopMatrix();
}


void a()
{
    // cloud position............................. (mini Cloud)
    //left
    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    //right
    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    //top left
    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();

    //top right
    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    //middle
    glPushMatrix();
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();

}

void c()
{
    // cloud color................................ //One Single Cloud

    glPushMatrix();
    // right, circle color (cloud)
    glColor3f (1,1,1);
    glTranslatef(35,10,0);
    a();
    glPopMatrix();


    glPushMatrix();
    // middle, circle color (cloud)
    glColor3f (1,1,1);
    glTranslatef(28,16,0);
    a();
    glPopMatrix();

    glPushMatrix();
    // left, circle color (cloud)
    glColor3f (1,1,1);
    glTranslatef(20,10,0);
    a();
    glPopMatrix();
}

void cloud()
{
    // Three Cloud........................ (full)

     // cloud right (full)
    glPopMatrix();
    glPushMatrix();
    glTranslatef(15.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();

     // cloud left (full)
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-40.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
}

void rect()
{
    // green color (rectangle)
    glRectf(-16.0, -16.0, 16.0, 16.0);
}
GLfloat ss=0.0;

void ground()
{
    // road........................

    glColor3f(0.8,0.498039,0.196078);
    glPushMatrix();
    glTranslatef(-70,-42,0);
    glBegin(GL_POLYGON);

    glVertex3f (-10, 0, 0.0);
    glVertex3f (-10,10, 0.0);
    glVertex3f (600,10, 0.0);
    glVertex3f (600,0, 0.0);

    glEnd();
}

void triangle(void)
{
    // jao tree.................................... (color)
    glColor3f (0.137255,0.556863,0.137255);

    glBegin(GL_POLYGON);

    glVertex3f (0, 0, 0.0);
    glVertex3f (9, 13, 0.0);
    glVertex3f (18, 0, 0.0);

    glEnd();
}


void tree2()
{
    // jao tree leaf........................

    glPushMatrix();
    glTranslatef(3,8,0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.5,14,0);
    glScalef(.9,.9,0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5,20,0);
    glScalef(.8,.8,0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7,26,0);
    glScalef(.5,.5,0);
    triangle();
    glPopMatrix();

    // jao tree gora.............................

    glPushMatrix();
    glBegin(GL_POLYGON);

    glColor3f(0.36,0.25,0.20);
    glVertex3f (10, 4, 0.0);
    glVertex3f (10, 8, 0.0);
    glVertex3f (14, 8, 0.0);
    glVertex3f (14, 4, 0.0);

    glEnd();
    glPopMatrix();

}
void tree()
{
    // green leaves....................................
    glPushMatrix();
    glTranslatef(35,10,0);
    a();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(28,16,0);
    a();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(20,10,0);
    a();

    glPopMatrix();
}
void treebody()
{
    // tree body .......................................
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(0,0,0);
    glVertex3f(2.5,2,0);
    glVertex3f(4.0,-2,0);
    glVertex3f(1,-4,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(7,2,0);
    glVertex3f(9,2,0);
    glVertex3f(8,-2,0);
    glVertex3f(4,-2,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1,-4,0);
    glVertex3f(4,-2,0);
    glVertex3f(8,-2,0);
    glVertex3f(7,-7,0);
    glVertex3f(1.5,-7,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1.5,-7,0);
    glVertex3f(7,-7,0);
    glVertex3f(6.5,-10,0);
    glVertex3f(2,-10,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(2,-10,0);
    glVertex3f(6.5,-10,0);
    glVertex3f(6.8,-13,0);
    glVertex3f(1.5,-13,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1.5,-13,0);
    glVertex3f(6.8,-13,0);
    glVertex3f(7,-18,0);
    glVertex3f(.5,-18,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(.5,-18,0);
    glVertex3f(7,-18,0);
    glVertex3f(3,-27,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(.5,-18,0);
    glVertex3f(2.5,-23,0);
    glVertex3f(-1,-25,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(7,-18,0);
    glVertex3f(8,-28,0);
    glVertex3f(4,-22,0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    bus();

    cx = cx + .02;
    if(cx>70)
        cx = -50; // back track kore abar asbe

    glutPostRedisplay();

    ///ground...............................
    glPushMatrix();
    glTranslatef(0.0,-35.0,0.0);
    glScalef(3.5,3.0,0.0);
    glColor3f(0.0, 0.5, 0.0);
    rect();       // green color (rectangle)
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(cx,17.0,0.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(cx,20.0,0.0);
    glPopMatrix();

    ///tree1.................................... green tree
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-49.0,9.5,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40.4,15.4,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();

    /// cloud .......................................
    glPushMatrix();
    glTranslatef(cx,0.0,0.0);
    glScalef(.8,1,0);
    cloud();
    glPopMatrix();

    ///tree typeA 1 ................................... jao tree
    glPushMatrix();
    glTranslatef(-5.0,-5.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();

    ///road.................................................
    glPushMatrix();
    glTranslatef(-10.0,15.0,0.0);
    ground();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10.0,20.0,0.0);
    ground();
    glPopMatrix();
    glPopMatrix();

    ///BUS ...................................................
    glPushMatrix();
    glTranslatef(cx, -15, 0);
    glScalef(30, 8, 0);
    bus();
    glPopMatrix();

    ///BUS2 .................................................
    glPushMatrix();
    glTranslatef(cx, -5, -15);
    glScalef(30, 8, 0);
    bus();
    glPopMatrix();


    ///tree3 ................................ green tree
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(22.0,-32.5,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(30.5,-26.5,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();

    ///tree typeD 1 .............................. jao tree
    glPushMatrix();
    glTranslatef(-10.0,-50.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();

    glFlush();
}

void init(void)
{
    glClearColor (0, 0.749, 1, 0);
    glOrtho(-50.0,50.0, -50.0, 50.0, -1.0, 1.0);
}

int main()
{
    printf(">><< Press N for nightmood>><< Press D for day mood >><<\n\n");
    printf("Click Mouse Left/Right Button for cloud movement\n\n");
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1350, 690);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("My Dream");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
