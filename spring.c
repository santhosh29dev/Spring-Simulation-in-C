#include <stdio.h>
#include "raylib.h"

#define FPS 120
#define WIDTH 900
#define HEIGHT 600
#define THICK 5
#define MASS_WIDTH 100
#define FLOOR_Y (HEIGHT*0.6)


float x_mass;

void drawSpring(){

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
    float v=20;
    SetTargetFPS(FPS);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10,10);
        dt=GetFrameTime();
        drawFloor();
        x_mass+=v * dt;
        drawMass();
        drawSpring();
        DrawText("Spring On Mass Simulation",WIDTH/10,100,30,GREEN);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}