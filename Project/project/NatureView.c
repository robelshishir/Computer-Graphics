#include<GL/glut.h>
#include<stdlib.h>
GLfloat x1,x2,y1,y2,x3,x4,y3,y4,x5,y5;
void edgedetect(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,int *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-y1)<0)
	{
		temp=x1; x1=x2; x2=temp;
		temp=y1; y1=y2; y2=temp;

	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	x=x1;
	for(i=y1;i<y2;i++)
	{
		if(x<le[i])
			le[i]=x;
		if(x>re[i])
			re[i]=x;
		x+=mx;

	}
}
void dp(GLint cx,GLint cy)
{

	glBegin(GL_POINTS);
 	glVertex2i(cx,cy);
	glEnd();

}

void scanfill(float x1,float y1, float x2, float y2, float x3, float y3,float x4,float y4)
{
	int le[1000],re[1000];
	int i,y;
	for(i=0;i<1000;i++)
	{
		le[i]=1000;
		re[i]=0;

	}
	edgedetect(x1,y1,x2,y2,le,re);
	edgedetect(x2,y2,x3,y3,le,re);
	edgedetect(x3,y3,x4,y4,le,re);
	edgedetect(x4,y4,x1,y1,le,re);
		for(y=0;y<1000;y++)
	{
		if(le[y]<=re[y])
			for(i=le[y]+1;i<re[y];i++)
				dp(i,y);
	}
}



void pix(GLint h,GLint k,GLint x,GLint y)
{
	dp(x+h,y+k);
	dp(x+h,-y+k);
	dp(-x+h,-y+k);
	dp(-x+h,y+k);
	dp(y+h,x+k);
	dp(y+h,-x+k);
	dp(-y+h,-x+k);
	dp(-y+h,x+k);

}
void cd(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		pix(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	pix(h,k,x,y);
}
void init()
{
	glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);

}
void display()
{

float i,j;
for(i=0;i<600;i+=0.5)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//sun
	glColor3f(1.0,0.0,0.0);
	cd(600,500,35);
	cd(600,500,30);
	cd(600,500,25);
	cd(600,500,20);
	cd(600,500,15);
	cd(600,500,10);
	cd(600,500,50);
	cd(600,500,45);
	cd(600,500,40);
	cd(600,500,5);
	cd(600,500,55);
	cd(600,500,60);


	glColor3f(0.0,0.8,0.3);
	glBegin(GL_QUADS);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,0);
	glVertex2i(0,0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);
	glVertex2i(0,250);
	glVertex2i(1000,250);
	glVertex2i(1000,200);
	glVertex2i(0,200);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
		glVertex2i(0,100);
		glVertex2i(0,130);
		glVertex2i(1000,130);
		glVertex2i(1000,100);
		glEnd();
	glColor3f(1.0,0.0,0.0);
	cd(30,220,10);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(20,220);
	glVertex2i(40,220);
	glVertex2i(30,230);
	glVertex2i(30,210);
	glVertex2i(37,227);
		glVertex2i(23,213);
		glVertex2i(37,213);
		glVertex2i(23,227);

		glVertex2i(5,230);
			glVertex2i(100,230);
			glVertex2i(100,230);
			glVertex2i(100,232);
				glVertex2i(100,232);
				glVertex2i(5,232);

				glVertex2i(7,232);
					glVertex2i(7,262);
					glVertex2i(17,232);
					glVertex2i(17,262);
					glVertex2i(27,232);
						glVertex2i(27,262);
						glVertex2i(37,232);
						glVertex2i(37,262);

						glVertex2i(47,232);
							glVertex2i(47,262);
							glVertex2i(57,232);
							glVertex2i(57,262);
							glVertex2i(7,242);
								glVertex2i(59,242);
								glVertex2i(7,252);
								glVertex2i(59,252);
								glVertex2i(99,233);
													glVertex2i(97,245);
													glVertex2i(101,233);
													glVertex2i(103,245);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(60,210);
		glVertex2i(60,230);
		glVertex2i(90,230);
		glVertex2i(92,233);
		glVertex2i(95,230);
			glVertex2i(97,230);
			glVertex2i(99,233);
			glVertex2i(101,233);

			glVertex2i(105,226);
				glVertex2i(102,226);
				glVertex2i(100,228);
				glVertex2i(98,228);
				glVertex2i(96,220);
					glVertex2i(95,210);
					glVertex2i(93,210);
					glVertex2i(93,220);

					glVertex2i(93,216);
						glVertex2i(65,216);
						glVertex2i(65,220);
						glVertex2i(65,210);
						glEnd();


//second cart


glColor3f(1.0,0.0,0.0);
	cd(230,220,10);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(220,220);
	glVertex2i(240,220);
	glVertex2i(230,230);
	glVertex2i(230,210);
	glVertex2i(237,227);
		glVertex2i(223,213);
		glVertex2i(237,213);
		glVertex2i(223,227);

		glVertex2i(205,230);
			glVertex2i(300,230);
			glVertex2i(300,230);
			//glVertex2i(105,224);
			//glVertex2i(105,224);
				glVertex2i(300,232);
				glVertex2i(300,232);
				glVertex2i(205,232);

				glVertex2i(207,232);
					glVertex2i(207,262);
					glVertex2i(217,232);
					glVertex2i(217,262);
					glVertex2i(227,232);
						glVertex2i(227,262);
						glVertex2i(237,232);
						glVertex2i(237,262);

						glVertex2i(247,232);
							glVertex2i(247,262);
							glVertex2i(257,232);
							glVertex2i(257,262);
							glVertex2i(207,242);
								glVertex2i(259,242);
								glVertex2i(207,252);
								glVertex2i(259,252);
								glVertex2i(299,233);
													glVertex2i(297,245);
													glVertex2i(301,233);
													glVertex2i(303,245);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(260,210);
		glVertex2i(260,230);
		glVertex2i(290,230);
		glVertex2i(292,233);
		glVertex2i(295,230);
			glVertex2i(297,230);
			glVertex2i(299,233);
			glVertex2i(301,233);

			glVertex2i(305,226);
				glVertex2i(302,226);
				glVertex2i(300,228);
				glVertex2i(298,228);
				glVertex2i(296,220);
					glVertex2i(295,210);
					glVertex2i(293,210);
					glVertex2i(293,220);

					glVertex2i(293,216);
						glVertex2i(265,216);
						glVertex2i(265,220);
						glVertex2i(265,210);
						glEnd();


	glColor3f(1.0,1.0,0.5);

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.0);
glVertex2i(20+i+i,850);
glVertex2i(30+i+i,820);
glVertex2i(100+i+i,820);
glVertex2i(110+i+i,800);
glVertex2i(200+i+i,800);
glVertex2i(200+i+i,815);
glVertex2i(190+i+i,830);
glVertex2i(180+i+i,830);
glVertex2i(170+i+i,860);
glVertex2i(155+i+i,860);
glVertex2i(150+i+i,870);
glVertex2i(135+i+i,860);
glVertex2i(115+i+i,860);
glVertex2i(100+i+i,825);
glVertex2i(30+i+i,850);
glEnd();
	//glClear(GL_COLOR_BUFFER_BIT);

cd(142+i+i,890,20);
cd(170+i+i,790,5);
cd(130+i+i,790,5);
cd(22+i+i,850,10);
glColor3f(0.0,0.0,0.0);
cd(30+i,110,10);
cd(80+i,110,10);
cd(130+i,110,10);
cd(170+i,110,10);

cd(225+i,110,10);
cd(265+i,110,10);

cd(320+i,110,10);
cd(360+i,110,10);

glBegin(GL_TRIANGLES);
glVertex2i(200+i+i+i,800);
glVertex2i(200+i+i+i,815);
glVertex2i(215+i+i+i,808);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(200+i+i+i+i,800);
glVertex2i(200+i+i+i+i,815);
glVertex2i(215+i+i+i+i,808);
//glEnd();
//glBegin(GL_TRIANGLES);
glVertex2i(200+i+i+i+i+i,800);
glVertex2i(200+i+i+i+i+i,815);
glVertex2i(215+i+i+i+i+i,808);
glEnd();
glBegin(GL_LINES);
glVertex2i(130+i+i,790);
glVertex2i(130+i+i,800);
glVertex2i(170+i+i,790);
glVertex2i(170+i+i,800);
glVertex2i(142+i+i,870);
glVertex2i(142+i+i,880);

glVertex2i(0,100);
glVertex2i(1000,100);
glVertex2i(0,130);
glVertex2i(1000,130);


for(j=0;j<=1000;j+=20)
{

	glVertex2i(10+j,100);
	glVertex2i(15+j,130);

}
glEnd();

glColor3f(0.0,0.8,1.2);
	glBegin(GL_POLYGON);
	glVertex2i(750,150);
	glVertex2i(750,260);
	glVertex2i(760,260);
	glVertex2i(760,150);
	glEnd();
	glColor3f(1.0,0.0,1.5);
		glBegin(GL_POLYGON);
		glVertex2i(900,150);
		glVertex2i(900,260);
		glVertex2i(910,260);
		glVertex2i(910,150);
		glEnd();
	glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2i(700,260);
		glVertex2i(950,260);
		glVertex2i(950,300);
		glVertex2i(700,300);
		glEnd();

glColor3f(0.0,0.0,0.0);
glRasterPos2i(710,270);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'C');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'C');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'R');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'A');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'I');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'L');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'W');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'A');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'Y');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'S');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'A');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'I');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'O');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'N');



glColor3f(0.0,0.0,1.0);
scanfill(15+i,120,15+i,160,95+i,160,95+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(15+i,160,25+i,170,105+i,170,95+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(95+i,160,105+i,170,105+i,130,95+i,120);

glColor3f(0.0,0.0,1.0);
scanfill(110+i,120,110+i,160,190+i,160,190+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(110+i,160,120+i,170,200+i,170,190+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(190+i,160,200+i,170,200+i,130,190+i,120);

glColor3f(0.0,0.0,1.0);
scanfill(205+i,120,205+i,160,285+i,160,285+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(205+i,160,215+i,170,295+i,170,285+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(285+i,160,295+i,170,295+i,130,288+i,120);

glColor3f(0.0,0.0,1.0);
scanfill(300+i,120,300+i,160,380+i,160,380+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(300+i,160,310+i,170,390+i,170,380+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(380+i,160,390+i,170,390+i,130,380+i,120);

glColor3f(1.0,0.0,0.0);
cd(388+i,150,3);

glBegin(GL_LINES);
glVertex2i(375+i,165);
glVertex2i(375+i,185);
glVertex2i(372+i,165);
glVertex2i(372+i,185);
glEnd();

glColor3f(0.0,1.0,0.5);
glBegin(GL_QUADS);
glVertex2i(0,500);
glVertex2i(0,550);
glVertex2i(100,600);
glVertex2i(200,500);
glEnd();

glColor3f(0.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(400,500);
glVertex2i(500,600);
glVertex2i(600,500);

glEnd();

glColor3f(0.0,0.5,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(100,500);
glVertex2i(300,600);
glVertex2i(500,500);

glEnd();

//second hill set


glColor3f(0.0,1.0,0.5);
glBegin(GL_TRIANGLES);
glVertex2i(600,500);
//glVertex2i(600,550);
glVertex2i(700,600);
glVertex2i(800,500);
glEnd();

glColor3f(0.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(800,500);
glVertex2i(1000,600);
glVertex2i(1000,500);

glEnd();

glColor3f(0.0,0.5,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(700,500);
glVertex2i(900,600);
glVertex2i(1000,500);
glEnd();
for(j=0;j<=90;j+=5)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(290,500+j);
	glVertex2i(310,500+j);
	glEnd();
}
glColor3f(1.5,0.8,1.2);
	glBegin(GL_POLYGON);
	glVertex2i(280,590);
	glVertex2i(280,615);
	glVertex2i(320,615);
	glVertex2i(320,590);
	glEnd();

	glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2i(280,615);
		glVertex2i(320,615);
		glVertex2i(310,650);
		glVertex2i(290,650);
		glEnd();
		glColor3f(1.0,1.0,1.0);
			glBegin(GL_LINES);
			glVertex2i(295,650);
			glVertex2i(295,655);
			glVertex2i(300,650);
			glVertex2i(300,655);
			glVertex2i(305,650);
			glVertex2i(305,655);
			glEnd();
			//tree
			int k;
			for(k=0;k<800;k+=150)
				{
				glColor3f(0.5,0.3,0.5);

	        glBegin(GL_POLYGON);
			glVertex2i(50+k,310);
			glVertex2i(50+k,350);
			glVertex2i(60+k,350);
			glVertex2i(60+k,310);
			glEnd();
			glColor3f(0.0,1.0,0.0);
			glBegin(GL_TRIANGLES);
			glVertex2i(40+k,350);
			glVertex2i(55+k,410);
			glVertex2i(70+k,350);
			glEnd();
			//house
			glColor3f(1.0,1.2,0.0);
				        glBegin(GL_POLYGON);
						glVertex2i(85+k,310);
						glVertex2i(85+k,350);
						glVertex2i(130+k,350);
						glVertex2i(130+k,310);
						glEnd();
						 glBegin(GL_POLYGON);
						 glColor3f(0.0,0.0,0.0);
						glVertex2i(100+k,310);
						glVertex2i(100+k,330);
						glVertex2i(115+k,330);
						glVertex2i(115+k,310);
						glEnd();
						glColor3f(0.0,1.0,1.0);
						glBegin(GL_TRIANGLES);
						glVertex2i(80+k,350);
						glVertex2i(105+k,380);
						glVertex2i(135+k,350);
						glEnd();
				}
glFlush();
}
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("dd");
	glutInitWindowPosition(0,0);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}

