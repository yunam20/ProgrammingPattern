// Lecture05.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#define DEBUG
//���ϰ� ���� ���� ������
#define ESC 27

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>

// game_state == 0�϶�
int print_title_screen()
{
    std::cout << "*******************************************************" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*                     �����̰���                      *" << std::endl;
    std::cout << "*                    (Snake Bite)                     *" << std::endl;
#ifdef DEBUG
    std::cout << "*                   - ����׸�� -                    *" << std::endl;
#else
    std::cout << "*                                                     *" << std::endl;
#endif
    std::cout << "*   1. ���� ����                                      *" << std::endl;
    std::cout << "*   2. ���� ����                                      *" << std::endl;
    std::cout << "*   3. ���� ��ŷ                                      *" << std::endl;
    std::cout << "*   4. ���� ���� (ESC)                                *" << std::endl;
    std::cout << "*******************************************************" << std::endl;

    return 0;
}

// game_state == 2�϶�
int print_introduction_screen()
{
    std::cout << "*******************************************************" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*                   - ���Ӽ��� -                    *" << std::endl;
    std::cout << "*         �����̸� �����̴� ��̳� �����Դϴ�!        *" << std::endl;
    std::cout << "*                                                     *" << std::endl;
    std::cout << "*          Ÿ��Ʋ ȭ������ ����Į���? (Y/N)          *" << std::endl;
    std::cout << "*******************************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y)
{
    //x, y ��ǥ ����
    COORD pos = { x, y };
    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//�������� ���� �ڵ�
/*
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
}*/

//������ ���� �ڵ�
int print_game_screen(int stage_width, int stage_height)
{
    // ���� ���
    std::cout << std::string(stage_width, '*') << '\n';
    // ��� �� ���
    for (int i = 2; i < stage_height; i++) {
        std::cout << '*' << std::string(stage_width - 2, ' ') << "*\n";
    }
    // �Ʒ��� ���
    std::cout << std::string(stage_width, '*') << '\n';

    // ��ǥ (5,5)�� ^^ ���
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
                    std::cout << "�ʺ�, ���̰��� �Է��ϼ��� (10 �̻�): ";
                    std::cin >> xnum; std::cin >> ynum;
                    if (xnum >= 10 and ynum >= 10) break;
                    else std::cout << "�߸��� ���� �Է��߽��ϴ�." << std::endl;
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