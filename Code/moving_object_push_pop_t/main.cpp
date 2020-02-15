#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static float	tx	=  0.0;
static float	ty	=  0.0;
float p=3;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-15,15,-15,15,-15,5);
}
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)

    {
        float angle = 2 * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    circle(3,3,p,0);

    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(8,8,0);
    circle(3,3,0,0);
    glColor3f(1.0f, 1.0f, 0.0f);
    glPopMatrix();

    if(p<=10)
        p=p+.005;
    else
        p=-15;

    glutPostRedisplay();

    glFlush();
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Push+pop+t+animation");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
