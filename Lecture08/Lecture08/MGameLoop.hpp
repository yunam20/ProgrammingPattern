//Ű ����
#define KEY_EXIT 27
#define KEY_ENTER 13
#define KEY_RIGHT 'd'
#define KEY_LEFT 'a'

//���� ����
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
		//x, y ��ǥ ����
		COORD pos{ x, y };
		//Ŀ�� �̵�
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	class MGameLoop
	{
	public:

		bool isGameRunning = false;

		void Initialize() //�ʱ�ȭ
		{
			isGameRunning = true;
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "�ʱ�ȭ �Ϸ�" << endl;
		}

		void Release()
		{
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "�ý��� ���� �Ϸ�" << endl;
		}

		void Update()
		{
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "������Ʈ �� �Ϸ�" << endl;

			if (_kbhit())
			{
				KeyEvent(_getch());
			}
		}

		void Render()
		{
			gotoxy(0, 10);
			cout << ANSI_COLOR_MAGENTA "������ �Ϸ�" << endl;
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
			case KEY_LEFT: //����
				gotoxy(2, 5);
				cout << ANSI_COLOR_YELLOW "����!" << endl;
				break;
			case KEY_RIGHT: //������
				gotoxy(2, 5);
				cout << ANSI_COLOR_YELLOW "������!" << endl;
				break;
			case KEY_EXIT: //���� ����Ű, �ѹ� ������ ����, �ι� ������ ����
				gotoxy(2, 12);
				cout << ANSI_COLOR_YELLOW "���� ������ �����Ͻðڽ��ϱ�?" << endl;
				gotoxy(2, 13);
				cout << "ESC = ����, �� �� �ƹ�Ű = ���" << endl;
				if (_getch() == KEY_EXIT) isGameRunning = false;
				break;
			default:
				break;
			}
		}
	};
}