// Lecture05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define DEBUG
//편하게 쓰기 위한 디파인
#define ESC 27

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>

// game_state == 0일때
int print_title_screen()
{
    std::cout << "*******************************************************" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*                     지렁이게임                      *" << std::endl;
    std::cout << "*                    (Snake Bite)                     *" << std::endl;
#ifdef DEBUG
    std::cout << "*                   - 디버그모드 -                    *" << std::endl;
#else
    std::cout << "*                                                     *" << std::endl;
#endif
    std::cout << "*   1. 게임 시작                                      *" << std::endl;
    std::cout << "*   2. 게임 설명                                      *" << std::endl;
    std::cout << "*   3. 게임 랭킹                                      *" << std::endl;
    std::cout << "*   4. 게임 종료 (ESC)                                *" << std::endl;
    std::cout << "*******************************************************" << std::endl;

    return 0;
}

// game_state == 2일때
int print_introduction_screen()
{
    std::cout << "*******************************************************" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*                   - 게임설명서 -                    *" << std::endl;
    std::cout << "*         지렁이를 움직이는 재미난 게임입니다!        *" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*          타이틀 화면으로 돌아칼까요? (Y/N)          *" << std::endl;
    std::cout << "*******************************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y)
{
    //x, y 좌표 설정
    COORD pos = { x, y };
    //커서 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//스테이지 생성 코드
int print_game_screen(int stage_width, int stage_height)
{
    for (int i = 1; i <= stage_height; i++) {
        if(i == 1 or i == stage_height)
        {
            for (int j = 1; j <= stage_width; j++) std::cout << "*";
            std::cout << "" << std::endl;
        }
        else
        {
            std::cout << "*";
            for (int j = 1; j <= (stage_width-2); j++) std::cout << " ";
            std::cout << "*" << std::endl;
        }
    }

    gotoxy(5, 5);
    std::cout << "^^";

    return 0;
}

int main()
{
    int game_state = 0;
    int is_game_running = 1;
    int xnum, ynum;

    while (is_game_running == 1)
    {
        system("cls");
        char key_input = 0;
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch (key_input)
            {
            case '1':
                while (1) {
                    std::cout << "너비, 높이값을 입력하세요 (10 이상): ";
                    std::cin >> xnum; std::cin >> ynum;
                    if (xnum >= 10 and ynum >= 10) break;
                    else std::cout << "잘못된 값을 입력했습니다." << std::endl;
                }
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                break;
            case '4':
                is_game_running = 0;
                break;
            case ESC:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            print_game_screen(xnum, ynum);
            key_input = _getch();
            break;
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}