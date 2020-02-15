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

    // cloud middle (full)
    glPushMatrix();
    glTranslatef(-15.0,30.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();

     // cloud right (full)
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();

     // cloud left (full)
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-60.0,25.0,0.0);
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


void day()
{
    // blue sky...........................
    glBegin(GL_POLYGON);
    glColor3f(sr,sg,sb);
    glVertex3f(-50,-3,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(80,50,0.0);
    glVertex3f(80,-3,0.0);
    glEnd();

     //sun.....................................
    glPushMatrix();
    glTranslatef(ss,0.0,0.0);
    glTranslatef(-20.0,40.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(1.0,1.0,0.0);
    circle(3);
    glPopMatrix();
}

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

void night ()
{
     //black sky..............................
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-50,-3,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(80,50,0.0);
    glVertex3f(80,-3,0.0);

    glEnd();
}

void moon()
{
    //moon........................ (night mood)
    glPushMatrix();
    glTranslatef(mn,0.0,0.0);
    glTranslatef(20.0,35.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(1.0,1.0,1.0);
    circle(3.5);
    glPopMatrix();

    glutPostRedisplay();
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


//////////////////////
///***HOME Start***////
//////////////////////

void home1()
{
    //1st Home
    //1
    glColor3ub(102,51,0);
    glBegin(GL_POLYGON);
    glVertex2d(3,14);
    glVertex2d(3,11);
    glVertex2d(10,8);
    glVertex2d(10,12);
    glVertex2d(6,18);
    glEnd();

    //2
    glColor3ub(153,153,0);
    glBegin(GL_POLYGON);
    glVertex2d(10,8);
    glVertex2d(10,12);
    glVertex2d(20,12);
    glVertex2d(20,8);
    glEnd();

    //3
    glColor3ub(0,100,200);
    glBegin(GL_POLYGON);
    glVertex2d(10,12);
    glVertex2d(6,18);
    glVertex2d(17,18);
    glVertex2d(21,12);
    glEnd();

    //4
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    glVertex2d(5,11);
    glVertex2d(5,12);
    glVertex2d(8,11);
    glVertex2d(8,10);
    glEnd();

    //5
    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2d(14,8);
    glVertex2d(14,10);
    glVertex2d(17,10);
    glVertex2d(17,8);
    glEnd();
}

void house()
{
    // rectangle.........
    glColor3ub(240,150,100);
    glBegin(GL_POLYGON);
    glVertex2d(33,23);
    glVertex2d(44,23);
    glVertex2d(44,30);
    glVertex2d(33,30);
    glEnd();

    // floor................. toya
    glColor3ub(0,105,105);
    glBegin(GL_POLYGON);
    glVertex2d(31,30);
    glVertex2d(46,30);
    glVertex2d(38.5,38);
    glEnd();

}
///HOME END///





void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    day();
    glPopMatrix();

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

    /// moon .....................................
    glPushMatrix();
    moon();
    glPopMatrix();

    /// cloud .......................................
    glPushMatrix();
    glTranslatef(cx,0.0,0.0);
    glScalef(.8,1,0);
    cloud();
    glPopMatrix();


    ///home 2 ....................................
    glPushMatrix();
    glTranslatef(-65.0,-20.0,0.0);
    house();
    glPopMatrix();


    ///home 1 ..................................................
    glPushMatrix();
    glTranslatef(-45.0,-10.0,0.0);
    home1();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(20.0,-15.0,0.0);
    home1();
    glPopMatrix();


    ///tree typeA 1 ................................... jao tree
    glPushMatrix();
    glTranslatef(-5.0,-5.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();


    ///tree typeB 1 .................................. jao tree
    glPushMatrix();
    glTranslatef(35.0,-5.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();


    ///tree typeC 1 .................................. jao tree
    glPushMatrix();
    glTranslatef(30.0,-15.0,0.0);
    glScalef(.5,1,0);
    tree2();
    glPopMatrix();



    ///tree2 ......................................... green tree
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-44.0,-1,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-35.0,5.0,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();

    ///home 4 .....................................
    glPushMatrix();
    glTranslatef(-10.0,-10.0,0.0);
    home1();
    glPopMatrix();
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

    ///home 3 .............................................
    glPushMatrix();
    glTranslatef(-5.0,-70.0,0.0);
    house();
    glPopMatrix();
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

void spinDisplay()
{
    cx = cx + .01;
    if(cx>70)
        cx = -70; // back track kore abar asbe

    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:  // left button press korle running hobe
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(spinDisplay);
        }
        break;

    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON: // right button press korle pause hobe
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;

    default:
        break;
    }
}

void keyDisplayAnimationDay()
{
    str=500.0;
    sr=0.0;
    sg=0.749;
    sb=1.0;

    ss = 0.0;

    mn = 500.0;
    glutPostRedisplay();
}

void keyDisplayAnimationNight()
{
    str = 0.0;
    sr=0.0;
    sg=0.0;
    sb=0.0;

    ss = 500.0;

    mn = 0.0;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'd':
        //day
        keyDisplayAnimationDay();
        break;

    case 'n':
        //night();
        keyDisplayAnimationNight();
        break;

    default:
        break;
    }
}
int main()
{
    printf(">><< Press N for nightmood>><< Press D for day mood >><<\n\n");
    printf("Click Mouse Left/Right Button for cloud movement\n\n");
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1350, 690);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("My Dream House");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
