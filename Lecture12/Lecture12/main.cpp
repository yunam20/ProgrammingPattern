#pragma once
#include "Engine.hpp"
#include <Windows.h>

using namespace MuSoeun;

class SnakeBody : public Object
{
	bool isPoison;
};

int main()
{
	bool isGameRunning = true;

	//디버그용
	Scene game;
	Object obj;
	Object ob2;
	game.width = 20;
	game.height = 10;
	obj.x = 5; obj.y = 5; obj.type = 'A';
	ob2.x = 5; ob2.y = 7; ob2.type = 'C';
	game.AddObject(obj);
	game.AddObject(ob2);

	//게임루프
	while (isGameRunning)
	{
		game.DrawScreenBuf();
		system("cls");
	}

	return 0;
}