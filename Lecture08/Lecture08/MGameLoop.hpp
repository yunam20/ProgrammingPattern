//키 설정
#define KEY_EXIT 27
#define KEY_ENTER 13
#define KEY_RIGHT 'd'
#define KEY_LEFT 'a'

//색상 설정
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

namespace MuSoeun
{

	void gotoxy(int x, int y)
	{
		//x, y 좌표 이동
		COORD pos{ x, y };
		//커서 이동
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	class MGameLoop
	{
	public:

		bool isGameRunning = false;
		bool isEnter = false;

		void Initialize() //초기화
		{
			isGameRunning = true;
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "초기화 완료" << endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "시스템 해제 완료" << endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "업데이트 중 완료" << endl;

			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}

		void Render()
		{
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "랜더링 완료" << endl;
		}

		MGameLoop() {};
		~MGameLoop() {};

		void Run()
		{
			Initialize();

			while (isGameRunning)
			{
				Update();
				Render();
			}

			Release();
		}

		void KeyEvent(char input_key)
		{
			switch (input_key)
			{
			case KEY_EXIT:
				isEnter = true;
				gotoxy(2, 12);
				cout << "정말 게임을 종료하시겠습니까?" << endl;
				gotoxy(2, 13);
				cout << ANSI_COLOR_YELLOW "[확인]";
				cout << ANSI_COLOR_MAGENTA "                [취소]" << endl;
				gotoxy(2, 13);
				while (true) {
					char ch = _getch();
					if (ch == KEY_ENTER)
					{
						if (isEnter) isGameRunning = false;
						system("cls");
						break;
					}
					else if (ch == KEY_RIGHT)
					{
						isEnter = false;
						gotoxy(2, 13);
						cout << ANSI_COLOR_MAGENTA "[확인]";
						cout << ANSI_COLOR_YELLOW "                [취소]" << endl;
						gotoxy(24, 13);
					}
					if (ch == KEY_LEFT)
					{
						isEnter = true;
						gotoxy(2, 13);
						cout << ANSI_COLOR_YELLOW "[확인]";
						cout << ANSI_COLOR_MAGENTA "                [취소]" << endl;
						gotoxy(2, 13);
					}
				}
				break;
			default:
				break;
			}
		}
	};
}