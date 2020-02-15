#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int num;
void display(void)
{
        glClear (GL_COLOR_BUFFER_BIT);

        int i,j;
        bool f = false;

        for(i=0;i<num;i+=100)
        {
          for(j=0;j<=num;j+=100)
          {
            if (f)
                {
                    glColor3ub(0,0,0);
                    f = !f;
                }
            else
                {
                    glColor3f(1,1,1);
                    f = !f;
                }
            glBegin(GL_QUADS);
            glVertex2i(i,j);
            glVertex2i(i,j+100);
            glVertex2i(i+100,j+100);
            glVertex2i(i+100,j);
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
    glOrtho(0.0, 1000.0, 0.0, 1000.0, -1.0, 1.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Chess BoardS");
    init ();

    scanf("%d",&num);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
