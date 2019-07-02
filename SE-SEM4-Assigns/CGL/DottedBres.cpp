#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

struct Point{
    int x;
    int y;
};

struct Point p1;
struct Point p2;
int count = 0;

int sign(int d){
    if(d < 0)return -1;
    else if(d > 0)return 1;
    else return 0;
}
void putpixel(int x,int y){
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();    
}
void bresenham(int x1,int y1,int x2,int y2){

    int DX = x2 -x1;
    int DY = y2 -y1;

    int Sx = sign(DX);
    int Sy = sign(DY);

    DX = abs(DX);
    DY = abs(DY);

    int D = max(DX,DY);
    double R = D /2;

    int x = x1;
    int y = y1;
    glPointSize(2.0);
    if(DX > DY){

        for(int  i = 0;i< D;i++){
            putpixel(x,y);

            x += Sx;
            R += DY;

            if(R >= DX){
                y += Sy;
                R -= DX;
            }
        }


    }else{
         
           for(int  i = 0;i< D;i++){
            putpixel(x,y);

            y += Sy;
            R += DX;

            if(R >= DY){
                x += Sx;
                R -= DY;
            }
        } 
    }
    
    glFlush();

}

void DDA(int x1,int y1,int x2,int y2){
    float DX = x2 - x1;
    float DY = y2 -y1;

    float x = x1;
    float y = y1;
    glPointSize(2.0);
    float steps = 0;
    if(abs(DX) > abs(DY))
        steps = abs(DX);
    else
    {
            steps = abs(DY);
    }

    float xInc = DX / steps;
    float yInc = DY / steps;

    for(int i = 0;i <= steps;i++){
        putpixel(x,y);
        x = x+xInc;
        y = y+yInc;
    }   
    
     glFlush();   
}

void mouse(int button,int state,int x,int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
         x = x - 300;
         y = 300 -y;
         p2.x = x;
         p2.y = y;
         count++;
          cout<<"\nX: "<<x;
         cout<<"\nY: "<<y;
    }

        
    if(count == 1){
        p1 = p2;
    }
    else{
        DDA(p1.x,p1.y,p2.x,p2.y);
        count = 0;
    }
}
void render(){
     glClear(GL_COLOR_BUFFER_BIT);
   
    // bresenham(-100,100,100,-100);
    glFlush();

}

void Init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300,300,-300,300);
    glFlush();
}


int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("2D Transformation");
    Init();
    glutMouseFunc(mouse);
    // glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;

}