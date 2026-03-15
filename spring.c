#include <math.h>
#include <stdio.h>
#include "raylib.h"

#define FPS 120
#define WIDTH 900
#define HEIGHT 600
#define THICK 5
#define MASS_WIDTH 100
#define FLOOR_Y (HEIGHT*0.6)
#define NUM_SE 15
#define SPRING_EL 70
#define K 20
#define X_REST (WIDTH/3)
#define FRICTION 0.5


float x_mass=WIDTH * 0.7;
float v=20;
float a=2;
typedef struct{
    Vector2 start,end;
}SpringElem;

SpringElem spring_elem[NUM_SE];



void drawSpring(){

    float x_springdelta=x_mass /NUM_SE;
    float y_end=sqrt(pow(SPRING_EL,2)-pow(x_springdelta,2));
    for(int i=0;i<NUM_SE;i+=2){
        
        Vector2 start={x_springdelta *i,FLOOR_Y-MASS_WIDTH/2+SPRING_EL/2};
        Vector2 end={start.x + x_springdelta,start.y-y_end};
        spring_elem[i]= (SpringElem) {start,end};
        DrawLineEx(start, end,THICK, LIGHTGRAY);
    }

    for(int i=1;i<NUM_SE;i+=2){
        Vector2 start=spring_elem[i-1].end;
        Vector2 end={start.x + x_springdelta,start.y+y_end};
        spring_elem[i]= (SpringElem){start,end};
        DrawLineEx(start, end,THICK, LIGHTGRAY);
    }

    
}


void drawFloor()
{
    Vector2 start={0,FLOOR_Y};
    Vector2 end={WIDTH,FLOOR_Y};
    DrawLineEx(start,end,THICK,GRAY);
}

void drawMass(){
    

    Rectangle rect={x_mass,FLOOR_Y-MASS_WIDTH-THICK/2, MASS_WIDTH,MASS_WIDTH};
    DrawRectangleRec(rect,YELLOW);
}

int main(){

    InitWindow(WIDTH, HEIGHT,"Simulating a Spring");



    float dt;
    SetTargetFPS(FPS);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10,10);
        dt=GetFrameTime();
        drawFloor();
        float friction=a>0? FRICTION : -FRICTION;
        a= -K*(x_mass-X_REST)-v*FRICTION;
        v+= a * dt;
        x_mass+=v*dt;
        drawMass();
        drawSpring();
        DrawText("Mass On Spring Simulation",WIDTH/10,100,30,GREEN);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}