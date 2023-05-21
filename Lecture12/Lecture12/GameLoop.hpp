#pragma once
#include "Engine.hpp"

using namespace MuSoeun;

class SnakeBody : public Object
{
	int snake;
};

int GameLoop()
{
	while (1)
	{
		game.DrawScreenBuf();
		system("cls");
	}
}