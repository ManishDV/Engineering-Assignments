#include<iostream>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

// void putpixel(int x,int y){

//     glBegin(GL_POINTS);
//         glVertex2i(x,y);
//     glEnd();
//     glFlush();
// }

struct point
{
    float x;
    float y;
};
struct point p1 = {0,0};
struct point h = {100,100};
struct point m = {150,0};
struct point s = {0,150};

int sangle = 0;
int mangle = 0;
int hangle = 0;



void DDA(int x1,int y1,int x2,int y2){

     float dx = x2 -x1;
     float dy = y2 - y1;

     float steps = 0;
     if(abs(dx) > abs(dy))
        steps = abs(dx);
     else
     {
            steps = abs(dy);
     }

     float xInc = dx /steps;
     float yInc = dy /steps;
     
     int x = x1;
     int y = y1;
        glBegin(GL_POINTS);
     
     for(int i = 0;i<= steps;i++){
              glVertex2i(x,y);  
     
         x+= xInc;
         y+= yInc;

     }
         glEnd();
  

    glFlush();
}
void circle(int cx,int cy,int radius){
    int x = 0;
    int y = radius;

    int dp = 3 -2 * radius;
    glBegin(GL_POINTS);
    while(x <= y){
        if(dp < 0){
            x++;
            dp += 4*x + 6;
        }else{
            x++;
            y--;
            dp += 4*(x-y)+10;
        }
        glVertex2i(cx+x,cy+y);
        glVertex2i(cx+y,cy+x);
        glVertex2i(cx+y,cy-x);
        glVertex2i(cx+x,cy-y);
        glVertex2i(cx-x,cy-y);
        glVertex2i(cx-y,cy-x);
        glVertex2i(cx-y,cy+x);
        glVertex2i(cx-x,cy+y);
    }
    glEnd();
    glFlush();
}

point rotate(point p,int angle){
    int orgx = p.x;
    float theta = angle * 3.14 /180;

    p.x = p.x*cos(theta) + p.y*sin(theta);
    p.y = -orgx*sin(theta) + p.y*cos(theta);
    
    return p;
}

void render(){

    glClear(GL_COLOR_BUFFER_BIT);
    int radius = 200;
    circle(0,0,radius);
    circle(0,0,190);

    h = rotate(h,1);
    s = rotate(s,1);
     m = rotate(m,1);
        

    DDA(p1.x,p1.y,h.x,h.y);
    DDA(p1.x,p1.y,m.x,m.y);
    DDA(p1.x,p1.y,s.x,s.y);
    // DDA(p1.x,p1.y,p2.x,p2.y);
    
    glFlush();
}


void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);

    glFlush();
}
void timer(int a){
glutPostRedisplay();

glutTimerFunc(1000/60,timer,0);
p1 = rotate(p1,2);
s = rotate(s,1);
sangle += 10;


    if(sangle == 60){
        m = rotate(m,1);
        mangle +=10;
        sangle = 0;
    }

    if(mangle == 60){
        h = rotate(h,1);
        mangle = 0;
        hangle += 1;
    }
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0 , 0);
    glutInitWindowSize(600,600);
    glutCreateWindow("CLOCK");

    init();
    glutDisplayFunc(render);
    glutTimerFunc(1000,timer,0);
   
    glutMainLoop();
    
    return 0;
}