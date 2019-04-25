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



void render(){

    glClear(GL_COLOR_BUFFER_BIT);
    int radius = 200;
    circle(0,0,radius / 2);
    circle(0,0,(radius/2) / 2);
    circle(0,0,3*radius/4);
    
    int angle = 0;
    for(int i = 0;i<7;i++){
        angle = angle + 60;
        int x = (radius/2) * cos(angle*3.14/180);
        int y = (radius/2) * sin(angle*3.14/180);
        circle(x,y,radius/4);        
    }
    
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

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0 , 0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Circle Pattern 1");

    init();

    glutDisplayFunc(render);
    glutMainLoop();
    
    return 0;
}