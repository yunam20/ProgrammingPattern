#pragma once

struct GameObject
{
    int posX;
    int posY;
    int isActive;
};

typedef enum {
    RIGHT = 1,
    LEFT,
    UP,
    DOWN
} Direction;

typedef enum {
    MAIN_SCREEN = 0,
    GAME_SCREEN,
    END_SCREEN,
    GAMEOVER_SCREEN,
    RANKING_SCREEN,
} GameState;

int Initialize();
int Release();
int DrawBuffer(int deltaTime);
int ProcessInput();
void EndScreen();
void GameOverScreen();
void MainScreen();
void RankingScreen();
void GameScreen(int deltaTime);
void CheckGameOver();
void MoveSnake();
void GameOver(int score);
void initApplePos();