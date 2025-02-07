#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>

#include "actors/player.hpp"

int main(int argc, char* argv[])
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hero");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    MaximizeWindow();

    Camera camera = { 0 };
    Player player(camera);

    while (!WindowShouldClose()) {
        // Update.
        float dt = GetFrameTime();

        player.Update(dt);

        // Draw.

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);

            // Camera/Scene draw.
            BeginMode3D(camera);
            {
                DrawGrid(10, 1);
                player.Draw();
            }
            EndMode3D();

            // UI draw.
            DrawFPS(10, 10);
            DrawText("Right Button - Rotate camera", 10, 50, 20, LIGHTGRAY);
            DrawText("Left Button - Move to location", 10, 70, 20, LIGHTGRAY);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}