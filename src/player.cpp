#include "player.h"
#include "raylib.h"

static Player player;

void InitPlayer()
{
    // 加载玩家纹理
    player.texture = LoadTexture("../assets/player.png");
    float scale = 0.1f;             // 设置缩放比例
    player.texture.width *= scale;  // 缩放纹理宽度
    player.texture.height *= scale; // 缩放纹理高度

    // 设置初始位置和速度
    player.position = (Vector2){0.0f, 0.0f};                                // 初始位置
    player.position.x = (GetScreenWidth() - player.texture.width) / 2.0f;   // 居中
    player.position.y = (GetScreenHeight() - player.texture.height) / 2.0f; // 居中
    player.speed = .5f;
}

void UpdatePlayer()
{
    // 检测键盘输入并更新玩家位置
    if (IsKeyDown(KEY_D))
        player.position.x += player.speed; // 向右移动
    if (IsKeyDown(KEY_A))
        player.position.x -= player.speed; // 向左移动
    if (IsKeyDown(KEY_S))
        player.position.y += player.speed; // 向下移动
    if (IsKeyDown(KEY_W))
        player.position.y -= player.speed; // 向上移动

    // 防止玩家超出屏幕
    if (player.position.x < 0 + player.texture.width / 2.0f)
        player.position.x = 0 + player.texture.width / 2.0f;
    if (player.position.x > GetScreenWidth() - player.texture.width / 2.0f)
        player.position.x = GetScreenWidth() - player.texture.width / 2.0f;
    if (player.position.y < 0 + player.texture.height / 2.0f)
        player.position.y = 0 + player.texture.height / 2.0f;
    if (player.position.y > GetScreenHeight() - player.texture.height / 2.0f)
        player.position.y = GetScreenHeight() - player.texture.height / 2.0f;
}

void DrawPlayer()
{
    // 绘制玩家
    DrawTexturePro(player.texture,
                   (Rectangle){0, 0, static_cast<float>(player.texture.width), static_cast<float>(player.texture.height)},
                   (Rectangle){static_cast<float>(player.position.x), static_cast<float>(player.position.y), static_cast<float>(player.texture.width), static_cast<float>(player.texture.height)},
                   (Vector2){player.texture.width / 2.0f, player.texture.height / 2.0f},
                   0.0f,
                   WHITE);
}

void UnloadPlayer()
{
    // 释放玩家资源
    UnloadTexture(player.texture);
}
