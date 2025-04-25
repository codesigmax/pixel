#include "raylib.h"
#include "game.h"
#include "player.h"

static Player player; // 声明玩家对象

void InitGame()
{
    // 设置窗口可调整大小
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // 初始化窗口
    InitWindow(800, 600, "PixelGame");

    // 初始化玩家
    InitPlayer();
}

void UpdateGame()
{
    // 更新玩家的位置
    UpdatePlayer();
}

void DrawGame()
{
    // 清除背景
    BeginDrawing();
    ClearBackground(RAYWHITE);
    // 绘制标题
    DrawText("PixelGame", 10, 10, 20, DARKGRAY);
    // 绘制FPS
    DrawFPS(10, 30);
    // 绘制玩家
    DrawPlayer();

    EndDrawing();
}

void CloseGame()
{
    // 释放资源
    UnloadPlayer(); // 卸载玩家资源
    CloseWindow(); // 关闭窗口
}
