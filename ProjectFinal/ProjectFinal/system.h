#pragma once

int GameState = 0;
int appleTime = 300;
int snakeBodyLength = 3;
int MovingTimeHorizontal = 50; // 가로 이동 속도 (ms)
int MovingTimeVertical = 100;  // 세로 이동 속도 (ms)
int deltaTimeSum = 0;
Direction direction = RIGHT;
int setScreenWidth = 70;
int setScreenHeight = 20;
int appleForm = '@';
int snakeForm = 'O';
#define BODY_LENGTH 1400

struct SnakeBody skin[BODY_LENGTH];
struct Apple apple;
struct Player player;

int Initialize();
int Release();
int DrawBuffer(int deltaTime);
int ProcessInput();