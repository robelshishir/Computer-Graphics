#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1,x2,y1,y2,m,dx,dy;
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    float i, j;

    if(dx==1)
    {
        for(i=x1,j=y1; i<=x2,j<=y2; i=i+1, j=j+m)
        {
            glBegin(GL_POINTS);
            glVertex3i(dx/100, dy/100, 0);
            glEnd();
        }
    }
    else if(dy==1)
    {
        for(i=x1,j=y1; i<=x2,j<=y2; i=i+(1/m), j=j+1)
        {
            glBegin(GL_POINTS);
            glVertex3i(dx/100, dy/100, 0);
            glEnd();
        }
    }
    else if(dx==(-1))
    {
        for(i=x1,j=y1; i>=x2,j>=y2; i=i+1, j=j-m)
        {
            glBegin(GL_POINTS);
            glVertex3i(dx/100, dy/100, 0);
            glEnd();
        }
    }
    else if(dy==(-1))
    {
        for(i=x1,j=y1; i>=x2,j>=y2; i=i-(1/m), j=j+1)
        {
            glBegin(GL_POINTS);
            glVertex3i(dx/100, dy/100, 0);
            glEnd();
        }
    }

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
    printf("Enter the value of x1:");
    scanf("%f", &x1);
    printf("Enter the value of y1:");
    scanf("%f", &y1);
    printf("Enter the value of x2:");
    scanf("%f", &x2);
    printf("Enter the value of y2:");
    scanf("%f", &y2);

    m = (y2-y1)/(x2-x1);

    if(m<=1)
    {
        if((x1>x2) && (y1>y2))
        {
            dx = -1;
        }
        else
        {
            dx = 1;
        }
    }

    else
    {
      if((x1<x2) && (y1>y2))
        {
            dy = -1;
        }
        else
        {
            dy = 1;
        }
    }

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("DDA Line Algorithm");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
