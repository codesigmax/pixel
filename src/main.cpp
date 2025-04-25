#include "raylib.h"
#include "game.h"

int main()
{
    // 初始化游戏
    InitGame();

    // 游戏主循环
    while (!WindowShouldClose())
    {
        // 更新游戏逻辑
        UpdateGame();

        // 渲染游戏画面
        DrawGame();
    }

    // 关闭游戏并释放资源
    CloseGame();

    return 0;
}
