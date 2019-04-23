#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
using namespace std;
#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);     glVertex2f((x1),(y1)); glVertex2f((x2),(y2)); glEnd();


struct point{
    GLfloat x;
    GLfloat y;
};
struct point p1;
struct point p2;
int  count = 0;
int CountDraw = 0;
int SB = 0;

void print(int x, int y,int z, char *string)
{
//set the position of the text in the window using the x and y coordinates
glRasterPos2f(x,y);
//get the length of the string to display
int len = (int)strlen(string);

//loop to display character by character
for (int i = 0; i<len; i++) 
{
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
}

}

void drawDDA(struct point p1,struct point p2){
  GLfloat dx = p2.x - p1.x;
    GLfloat dy = p2.y - p1.y;

    GLfloat x1 = p1.x;
    GLfloat y1 = p1.y;

    GLfloat step = 0;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    GLfloat xInc = dx / step;
    GLfloat yInc = dy / step;
   
    glBegin(GL_POINTS);
    for (float i = 1; i <= step; i++)
    {
        cout<<"\nCountDraw: "<<CountDraw;
        cout<<"\nI: "<<i;
        CountDraw++;
        
        //For( _____ _ ____ _ ______ _ ________ _ _______) this type of line.
        
        
        // if(CountDraw < 50 && SB == 0){
        //     glColor3f(0.0,0.0,0.0);
        // }

        // if(CountDraw > 50 && CountDraw < 65 && SB == 0){
        //     glColor3f(1.0,1.0,1.0);
        // }
        // if(CountDraw > 65 && SB == 0){
        //     CountDraw = 0;
        //     SB = 1;
        // }

        // if(CountDraw < 15 && SB == 1){
        //     glColor3f(0.0,0.0,0.0);
        // }

        // if(CountDraw > 15 && CountDraw < 30 && SB == 1){
        //     glColor3f(1.0,1.0,1.0);
        // }
        // if(CountDraw > 30 && SB == 1){
        //     CountDraw = 0;
        //     SB = 0;
        // }


        // For (--------------------) this type of line.

        if(CountDraw < 50){
            glColor3f(0.0,0.0,0.0);
        }

        if(CountDraw > 50 && CountDraw < 100){
            glColor3f(1.0,1.0,1.0);
        }
        if(CountDraw > 100){
            CountDraw = 0;
           
        }


        // For (_ _ _ _ _ _ _ _ _ _ _ _ _) this type of line.

        // if(CountDraw < 20){
        //     glColor3f(0.0,0.0,0.0);
        // }

        // if(CountDraw > 20 && CountDraw < 30){
        //     glColor3f(1.0,1.0,1.0);
        // }
        // if(CountDraw >  40){
        //     CountDraw = 0;
           
        // }

            
        glVertex2f(ceil(x1), ceil(y1));
        x1 += xInc;
        y1 += yInc;
         

    }
    glEnd();
    glFlush();
}
void mouse(int button,int state,int x,int y){
    
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
         cout<<"\nX: "<<x;
         cout<<"\nY: "<<y;
         p1.x =2*x - 400;
         p1.y =400 - 2*y; 
         count++;
         cout<<"\nX: "<<p1.x;
         cout<<"\nY: "<<p1.y;
         cout<<"\n\n";
    }
    if(count == 1)
        p2 = p1;

    if(count == 2){
        
        drawDDA(p2,p1);
        count = 0;       
    }
 
}
void render(){
    struct point p3 = {-400,0};
    struct point p4 = {400,0};
    
    //    drawDDA(p3,p4);

    glBegin(GL_LINES);
        glVertex2f(p3.x,p3.y);

        glVertex2f(p4.x,p4.y);
    glEnd();
       p3 = {0,400};
       p4 = {0,-400};
    // drawDDA(p3,p4);
    glPointSize(5.0);
    glBegin(GL_LINES);
        glVertex2f(p3.x,p3.y);

        glVertex2f(p4.x,p4.y);
    glEnd();
    glEnable(GL_LINE_SMOOTH);
    
     print(-70,-25,10,(char *)"(0,0)");  
    glFlush();
}




void Init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(-400,400,-400,400);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFlush();
}





int main(int argc ,char** argv){
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
        glutInitWindowPosition(400,400);
        glutInitWindowSize(400,400);
        glutCreateWindow("Dotted Line Pattern 1");
        Init();
        glutDisplayFunc(render);
        glutMouseFunc(mouse);
        glutMainLoop();
        return 0;
}