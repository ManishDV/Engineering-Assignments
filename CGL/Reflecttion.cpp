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

struct point{
    int x;
    int y;
};


point p1 = {50,50};
point p2 = {100,150};
point p3 = {150,50};

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
void render(){

    glClear(GL_COLOR_BUFFER_BIT);
  
DDA(-300,0,300,0);
DDA(0,300,0,-300);
  glColor3f(0.23,0.46,0.89);
   glBegin(GL_TRIANGLES);   

        glVertex2f(p1.x,p1.y);
        glVertex2f(p2.x,p2.y);
        glVertex2f(p3.x,p3.y);
        

   glEnd();
    
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

void aboutX(){
        p1.x = -p1.x;
        p2.x = -p2.x;
        p3.x = -p3.x;

       glutPostRedisplay(); 
}

void aboutY(){
        p1.y = -p1.y;
        p2.y = -p2.y;
        p3.y = -p3.y;

       glutPostRedisplay(); 
}


void aboutO(){
        p1.y = -p1.y;
        p2.y = -p2.y;
        p3.y = -p3.y;

         p1.x = -p1.x;
        p2.x = -p2.x;
        p3.x = -p3.x;

       glutPostRedisplay(); 
}
point swap(point p){
    int dummy;
    dummy = p.x;
    p.x = p.y;
    p.y = dummy;

    return p;    
}


point swap2(point p){
    int dummy;
    dummy = p.x;
    p.x = -p.y;
    p.y = -dummy;

    return p;    
}
void aboutYX(){
       
       p1 = swap(p1);
       p2 = swap(p2);
       p3 = swap(p3);
       glutPostRedisplay();
       
}
void aboutYMX(){
       
       p1 = swap2(p1);
       p2 = swap2(p2);
       p3 = swap2(p3);
       glutPostRedisplay();
       
}

void menu(int choice){

    switch (choice)
    {
        case 1:
            aboutX();
            break;
        case 2:
            aboutY();
            break;
        case 3:
            aboutO();
            break;
        case 4:
            aboutYX();
            break;
        case 5:
            aboutYMX();
            break;
                    
        default:
            break;
    }
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0 , 0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Circle Pattern 1");
        glutCreateMenu(menu);
        glutAddMenuEntry("1)Reflect About X - Axis",1);
        glutAddMenuEntry("2)Reflect About Y - Axis",2);
        glutAddMenuEntry("3)Reflect About Origin",3);
        glutAddMenuEntry("4)Reflect About Line Y = X",4);
        glutAddMenuEntry("5)Reflect About Line X = Y",5);
        
        glutAddMenuEntry("6)Exit",5);
        glutAttachMenu(GLUT_RIGHT_BUTTON);    
    
    init();

    glutDisplayFunc(render);
    glutMainLoop();
    
    return 0;
}