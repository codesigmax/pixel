#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player
{
    Texture2D texture;
    Vector2 position;
    float speed;
} Player;

void InitPlayer();
void UpdatePlayer();
void DrawPlayer();
void UnloadPlayer();

#endif // PLAYER_H
