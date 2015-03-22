#include <cstdlib>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>

typedef double point[3]; static double intnewball;
point a,b,c,d;//for the drawing the paddle object
point ba,bb,bc,bd;//for drawing the ball object 
point wa,wb,wc,wd;//for drawing the wall(border)
static float xmove=0.0;
static int release=0;static double yy=0.00;double xx=0.00;
static bool start=true; static bool k1,k2,k3,k4=true;
static bool firstmove=true;static bool lastmove=false;static bool borderrightedge=false;static bool borderleftedge=false;static bool bordertopedge=false;static bool borderbottomedge=false;
double  static newball[4][3]={{0.6,0.25,0.0},{0.6,0.28,0.0},{0.62,0.28,0.0},{0.62,0.25,0.0}}; 
/*float top_limit=1.2;
	float bottom_limit=0.0;
	float right_limit=1.20;
	float left_limit=0.0;*/

static int reac_top;

using namespace std;

GLfloat xangle=0.0;
float changeDir=1;// positive direction
double static paddle[4][3]={   {0.5,0.2,0.0},{ 0.5,0.25,0.0},{0.7,0.25,0.0},{0.7,0.2,0.0}};
double static ball[4][3]={{0.6,0.25,0.0},{0.6,0.28,0.0},{0.62,0.28,0.0},{0.62,0.25,0.0}}; 
double static border[4][2]={{0,0},{0,1.2},{1.2,1.2},{1.2,0.0}};
void renderoutline(point wa,point wb,point wc,point wd)
{
    glBegin(GL_LINE_LOOP);

    glColor3f(1,0,0);
    glVertex3dv(wa);
    glColor3f(1,0,0);
    glVertex3dv(wb);
    glColor3f(1,0,0);
    glVertex3dv(wc);
    glColor3f(1,0,0);
    glVertex3dv(wd);

    glEnd();
}

void ballrender(point ba,point bb,point bc,point bd)
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
     glVertex3dv(ba);
    glColor3f(0,0,1);
     glVertex3dv(bb);
    glColor3f(0,0,1);
     glVertex3dv(bc);
    glColor3f(0,0,1);
     glVertex3dv(bd);

    glEnd();
}

void renderbox1( point a , point b , point c, point d)
{
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3dv(a);
    glColor3f(0,0,0);
    glVertex3dv(b);
    glColor3f(0,0,0);
    glVertex3dv(c);
    glColor3f(0,0,0);
    glVertex3dv(d);
    glEnd();
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
    case 'a':xangle-=0.1;
        ++xmove;
        while(xmove>5)
        {
            xmove=-5;
            xangle=0.5;
            continue;
        }
        break;

    case 'd':xangle+=0.1;
        --xmove;
        while(xmove<-5)
        {
            xmove=5;
            xangle =-0.5;
            continue;
        }
        break;

    case 'r': 
        release=1;
		start=true;
        break;
    }
}

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    glOrtho(0, 1.2, 0, 1.2,-10.0,10.0); 

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glLineWidth(3.0);
    glLoadIdentity();

    glTranslatef(xangle,0,0);
    renderbox1(paddle[0],paddle[1],paddle[2],paddle[3]); // To draw the paddle 
	
    glPopMatrix();
    renderoutline(border[0],border[1],border[2],border[3]);

    glPushMatrix();
	glLoadIdentity();
	//glScalef(0.0,2.0,0);
    glTranslatef(xx,yy,0);
	
    	ballrender(ball[0],ball[1],ball[2],ball[3]);
		
    glPopMatrix();

    glFlush();
	glutSwapBuffers();

}

void moveBall()
{
	
		
   /* if(release==1)
    {
        //Release becomes one when the key 'r' is pressed (glutkeyboardfunc)
      

         if(yy>=(top_limit-ball[1][1]))
        {
            //when the boll reaches top 
            yy=yy-0.05;
            reac_top=3;
            printf("2222222222222\n");

        }
        else if( (yy<(top_limit-ball[1][1]))&& (reac_top==3)&&(yy>0.05))   //The balls journey back to the paddle 
        {
            printf("3\n");
            yy=yy-0.05;

        }   

		else  if(yy>=0&&yy<=(top_limit-ball[1][1]) )
        {
            reac_top=false;
            yy=yy+0.05;printf("1\n");//The ball which was intially on the paddle starts moving till it reaches the top edge of thescreen 
        } 
        release=1;
		}
		*/
	
	if (release==1)
	{
	

		if((newball[1][0]>border[0][0] && firstmove==true && borderleftedge==false))
		{
			
			
				
			printf("%f\t%f\n",newball[1][0],newball[1][1]);
			yy+=0.02;xx-=0.02;
			newball[0][0]-=0.02;newball[0][1]+=0.02;
			newball[1][0]-=0.02;newball[1][1]+=0.02;
			newball[2][0]-=0.02;newball[2][1]+=0.02;
			newball[3][0]-=0.02;newball[3][1]+=0.02;
			//intnewball=newball[1][0];
			
			
			

			// if(intnewball==newball[1][0]){printf("comon");}
			//printf("%f\n",newball[2][1]);
			
			
		}
		
		else	if((newball[1][1]<border[1][1] && bordertopedge==false))
		{
			

			printf("im here2\t");printf("%f\t%f\n",newball[1][1],newball[2][0]);
			 firstmove=false;
			 borderleftedge=true;
			printf("start is false");
			yy+=0.02;xx+=0.02;

			newball[0][0]+=0.02;newball[0][1]+=0.02;
			newball[1][0]+=0.02;newball[1][1]+=0.02;
			newball[2][0]+=0.02;newball[2][1]+=0.02;
			newball[3][0]+=0.02;newball[3][1]+=0.02;

			
			
		}
		else	if((newball[2][0]<border[2][2] && borderrightedge==false))

		{
			
			
			printf("im here3\t");printf("%f\t%f\n",newball[2][0],newball[2][1]);
			
			 bordertopedge=true;
			yy-=0.02;xx+=0.02;

			newball[0][0]+=0.02;newball[0][1]-=0.02;
			newball[1][0]+=0.02;newball[1][1]-=0.02;
			newball[2][0]+=0.02;newball[2][1]-=0.02;
			newball[3][0]+=0.02;newball[3][1]-=0.02;
		}

		else	if((newball[0][1]>border[3][1] && borderbottomedge==false ))
		{
			
			
			printf("im here4\t");printf("%f\t%f\n",newball[2][0],newball[2][1]);
			
			borderrightedge=true;
			//borderleftedge=false;
			
			firstmove=true;
			
			yy-=0.02;xx-=0.02;

			newball[0][0]-=0.02;newball[0][1]-=0.02;
			newball[1][0]-=0.02;newball[1][1]-=0.02;
			newball[2][0]-=0.02;newball[2][1]-=0.02;
			newball[3][0]-=0.02;newball[3][1]-=0.02;
		}
		
		/*else	if(newball[0][0]>border[0][0]&& borderleftedge==false)
		{
			
			borderbottomedge=true;
			firstmove=true;
			 
			printf("im here5\t");printf("%f\t%f\n",newball[2][0],newball[2][1]);
			
			
			yy+=0.02;xx-=0.02;

			newball[0][0]-=0.02;newball[0][1]+=0.02;
			newball[1][0]-=0.02;newball[1][1]+=0.02;
			newball[2][0]-=0.02;newball[2][1]+=0.02;
			newball[3][0]-=0.02;newball[3][1]+=0.02;
		}*/
		
		else	if(newball[1][0]>border[0][0] && firstmove==true && borderleftedge==true)
		{
			
			borderbottomedge=true;
				//bordertopedge=false;

			printf("%f\t%f\n",newball[1][0],newball[1][1]);
			yy+=0.02;xx-=0.02;
			newball[0][0]-=0.02;newball[0][1]+=0.02;
			newball[1][0]-=0.02;newball[1][1]+=0.02;
			newball[2][0]-=0.02;newball[2][1]+=0.02;
			newball[3][0]-=0.02;newball[3][1]+=0.02;
			//intnewball=newball[1][0];
			
			
			

			// if(intnewball==newball[1][0]){printf("comon");}
			//printf("%f\n",newball[2][1]);
			
			
		}
		
		release=1;
	}
    
}

void timer( int value )
{
    moveBall();

    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}

int main(int argc ,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(200,0);
    glutCreateWindow("3d Gasket");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
}
