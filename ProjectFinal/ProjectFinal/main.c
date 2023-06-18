#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include "game.h"
#include "util.h"
#include "screen.h"
#include "data.h"

GameState gameState = 0;
float appleTime = 20;
int snakeBodyLength = 4;
int MovingTimeHorizontal = 50; // ���� �̵� �ӵ� (ms)
int MovingTimeVertical = 100;  // ���� �̵� �ӵ� (ms)
int deltaTimeSum = 0;
Direction direction = RIGHT;
int setScreenWidth = 100;
int setScreenHeight = 30;
int appleForm = '@';
int snakeForm = 'O';
int startAnim = 1;

#define BODY_LENGTH 1400
struct GameObject skin[BODY_LENGTH];
struct GameObject apple;
struct GameObject player;

int isGameRunning = 1;

int main()
{
    CHECKERROR(Initialize());

    unsigned long time_end = GetTickCount();
    unsigned long deltaTime = GetTickCount();

    while (isGameRunning)
    {
        ProcessInput();
        DrawBuffer(deltaTime);
        deltaTime = GetTickCount() - time_end;
        time_end = GetTickCount();
        if (deltaTime < 33)
            Sleep(33 - deltaTime);
    }

    CHECKERROR(Release());

    exit(1);
    return 0;
}

int Initialize()
{
    //���� ����
    appleTime = 20;
    deltaTimeSum = 0;
    MovingTimeHorizontal = 50;
    MovingTimeVertical = 100;
    direction = RIGHT;
    setScreenWidth = 70;
    setScreenHeight = 20;
    appleForm = '@';
    snakeForm = 'O';
    startAnim = 1;

    //�÷��̾� �ʱ�ȭ
    player.posX = setScreenWidth / 2;
    player.posY = setScreenHeight / 2;

    //�� ������ �ʱ�ȭ
    snakeBodyLength = 4;

    int i = 0;
    while (i < BODY_LENGTH)
    {
        skin[i].isActive = 0;
        skin[i].posX = player.posX;
        skin[i].posY = player.posY;

        i = i + 1;
    }

    //��� �ʱ�ȭ
    initApplePos();

    i = 0;
    while (i < snakeBodyLength)
    {
        skin[i].isActive = 1;
        skin[i].posX = player.posX - i;
        skin[i].posY = player.posY;

        i = i + 1;
    }

    //ȭ�� �ʱ�ȭ
    setScreenSize(setScreenWidth, setScreenHeight);
    setCursorIcon(0);
    ClearBuffer();

    return 0;
}

int Release()
{
   // �迭 ������ ���� �迭�� �Ǿ� �ֱ� ������ ������ ������ �ʿ����� �ʽ��ϴ�.

    return 0;
}

int DrawBuffer(int deltaTime)
{
    //��� �׸���
    SetColor(0b0000, 0b0111);
    setCursorPos(0, 0);
    printf("%s", ScreenBuffer);
    switch (gameState) {
    case 0: MainScreen(); break;
    case 1: GameScreen(deltaTime); break;
    case 2: EndScreen(); break;
    case 3: GameOverScreen(); break;
    case 4: RankingScreen(); break;
    }
}

int ProcessInput()
{
    if (_kbhit())
    {
        int key = _getch();
        switch (gameState)
        {
        case MAIN_SCREEN:
            switch (key) {
            case '1': gameState = GAME_SCREEN; break;
            case '2': gameState = RANKING_SCREEN; break;
            case '3': isGameRunning = 0; break;
            default: break;
            }
            break;
        case GAME_SCREEN:
            switch (key) {
            case 'w': if (direction != DOWN) direction = UP; break;
            case 'a': if (direction != RIGHT) direction = LEFT; break;
            case 's': if (direction != UP) direction = DOWN; break;
            case 'd': if (direction != LEFT) direction = RIGHT; break;
            case 27: gameState = END_SCREEN; break;
            default: break;
            }
            break;
        case END_SCREEN:
            switch (key) {
            case '1': Initialize(); gameState = MAIN_SCREEN; break;
            case '2': gameState = GAME_SCREEN; break;
            default: break;
            }
            break;
        case GAMEOVER_SCREEN:
            switch (key) {
            case '1': Initialize(); gameState = GAME_SCREEN; break;
            case '2': Initialize(); gameState = MAIN_SCREEN; break;
            default: break;
            }
            break;
        case RANKING_SCREEN:
            switch (key)
            {
            case '1': Initialize(); gameState = MAIN_SCREEN; break;
            default: break;
            }
            break;
        }
    }
}

void EndScreen()
{
    printf("                                          \n                                               ");
    SetColor(0b0000, 0b0111);
    setCursorPos((setScreenWidth / 2 - 20), (setScreenHeight / 2 - 3));
    printf("[Are you sure you want to quit the game?]");
    setCursorPos((setScreenWidth / 2) - 3, (setScreenHeight / 2) + 2);
    printf("1. YES");
    setCursorPos((setScreenWidth / 2) - 3, (setScreenHeight / 2) + 4);
    printf("2. NO");
    setCursorPos(0, (setScreenHeight + 5));
}

void GameOverScreen()
{
    printf("                                          \n                                               ");
    SetColor(0b0000, 0b0111);
    setCursorPos((setScreenWidth / 2 - 5), (setScreenHeight / 2 - 5));
    setCursorPos((setScreenWidth / 2 - 5), (setScreenHeight / 2 - 3));
    printf("[GAME OVER]");
    setCursorPos((setScreenWidth / 2) - 5, (setScreenHeight / 2) + 2);
    printf("1. Restart");
    setCursorPos((setScreenWidth / 2) - 5, (setScreenHeight / 2) + 4);
    printf("2. Quit Game");
    setCursorPos(0, (setScreenHeight + 5));
}

void MainScreen()
{
    setCursorPos((setScreenWidth / 2) - 7, (setScreenHeight / 2) - 3);
    SetColor(0b0000, 0b0111);
    printf("[APPLE SNAKE GAME]");
    setCursorPos((setScreenWidth / 2) - 5, (setScreenHeight / 2) + 2);
    printf("1. Game Start");
    setCursorPos((setScreenWidth / 2) - 5, (setScreenHeight / 2) + 4);
    printf("2. Ranking");
    setCursorPos((setScreenWidth / 2) - 5, (setScreenHeight / 2) + 6);
    printf("3. Exit Game");
}

void RankingScreen()
{
    ReadScoresFromFile();
    DisplayScores(setScreenWidth, setScreenHeight, setCursorPos);
    setCursorPos((setScreenWidth / 2) - 2, (setScreenHeight / 2) + 8);
    printf("1. Return");
}

void GameScreen(int deltaTime)
{
    for (int i = 3; startAnim == 1; i--)
    {
        setCursorPos(setScreenWidth/2, setScreenHeight/2);
        if (i == 0) {
            startAnim = 0;
            printf("START!");
        }
        else printf("%d", i);
        Beep(600-(i*100), 750);
    }

    if (deltaTime > 0)
        deltaTimeSum += deltaTime;

    appleTime -= 1.0 / 33;
    const int movingTime = (direction == RIGHT || direction == LEFT) ? MovingTimeHorizontal : MovingTimeVertical;

    if (deltaTimeSum >= movingTime)
    {

        for (int i = snakeBodyLength - 1; i > 0; i--)
        {
            skin[i].posX = skin[i - 1].posX;
            skin[i].posY = skin[i - 1].posY;
        }

        switch (direction) {
        case RIGHT:
            player.posX += 1;
            break;
        case LEFT:
            player.posX -= 1;
            break;
        case UP:
            player.posY -= 1;
            break;
        case DOWN:
            player.posY += 1;
            break;
        default:
            break;
        }

        skin[0].posX = player.posX;
        skin[0].posY = player.posY;

        if (player.posX == apple.posX && player.posY == apple.posY)
        {
            skin[snakeBodyLength].posX = skin[snakeBodyLength - 1].posX;
            skin[snakeBodyLength].posY = skin[snakeBodyLength - 1].posY;
            skin[snakeBodyLength].isActive = 1;
            snakeBodyLength++;

            initApplePos();

            // ����� �Ծ��� ���� �ִϸ��̼�
            for (int count = 0; count < 2; count++)
            {
                for (int i = 0; i < snakeBodyLength; i++)
                {
                    setCursorPos(skin[i].posX, skin[i].posY);
                    printf("%c", snakeForm);
                }

                Beep(300, 100);

                for (int i = 0; i < snakeBodyLength; i++)
                {
                    setCursorPos(skin[i].posX, skin[i].posY);
                    printf(" ");
                }

                // ��� ���
                Beep(300, 100);

                appleTime = 20;
            }
        }

        // ���ӿ��� ����
        if ((player.posX <= 0 || player.posX >= setScreenWidth || 
            player.posY <= 0 || player.posY >= setScreenHeight) ||
            appleTime <= 0) GameOver(snakeBodyLength);
        for (int i = 1; i < snakeBodyLength; i++)
        {
            if (skin[0].posX == skin[i].posX && skin[0].posY == skin[i].posY)
            {
                GameOver(snakeBodyLength);
            }
        }

        deltaTimeSum = 0;
    }

    SetColor(0b0000, 0b1010);
    for (int i = 0; i < snakeBodyLength; i++)
    {
        setCursorPos(skin[i].posX, skin[i].posY);
        printf("%c", snakeForm);
    }

    setCursorPos(apple.posX, apple.posY);
    SetColor(0b0000, 0b0100);
    printf("%c", appleForm);

    SetColor(0b0000, 0b0111);
    setCursorPos(0, (setScreenHeight + 2));

    if (deltaTime != 0)
        printf(" * Delta Time: %d\t* fps: %d\n * Limit: %.1lf\t\t* Snake Length: %d",
            deltaTime, (1000 / deltaTime), appleTime, snakeBodyLength);
}

void GameOver(int score)
{
    setCursorPos(setScreenWidth / 2 - 4, setScreenHeight / 2);
    Beep(300, 100);
    SetColor(0b0000, 0b0100);
    printf("YOU DIED");
    SetColor(0b0000, 0b0111);
    setCursorPos(0, (setScreenHeight + 2));
    printf("                                          \n                                               ");
    char playerName[4];
    do {
        setCursorPos(0, (setScreenHeight + 2));
        printf(" * YOUR NAME (3): ");
        scanf("%3s", playerName);  // �Է� ���̸� 3���� ����
    } while (strlen(playerName) != 3);  // �̸��� ���̰� 3�� �ƴ� ��� ���Է� ��û

    ReadScoresFromFile();
    AddNewScore(playerName, score);
    WriteScoresToFile();
    gameState = GAMEOVER_SCREEN;
}

void initApplePos()
{
    srand(time(NULL));

    //��� ������ �ʱ�ȭ
    apple.isActive = 0;

    while (1)
    {
        apple.posX = rand() % setScreenWidth;
        apple.posY = rand() % setScreenHeight;

        // ���� �������� �ʵ��� ���� ó��
        if ((apple.posX >= 1 && apple.posX <= (setScreenWidth-1))
            && (apple.posY >= 1 && apple.posY <= (setScreenHeight-1)))
            break;
    }

    int i = 0;
    while (i < BODY_LENGTH)
    {
        if (skin[i].posX == apple.posX && skin[i].posY == apple.posY)
        {
            apple.posX = rand() % setScreenWidth;
            apple.posY = rand() % setScreenHeight;
            i = 0;
        }
        else
        {
            i = i + 1;
        }
    }
}