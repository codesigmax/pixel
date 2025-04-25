#include "raylib.h"

int main()
{
    // 初始化窗口
    InitWindow(800, 600, "PixelGame");

    // 设置帧率
    SetTargetFPS(60);

    // 游戏主循环
    while (!WindowShouldClose())
    {
        // 更新逻辑

        // 绘制
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, PixelGame!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // 关闭窗口
    CloseWindow();

    return 0;
}
