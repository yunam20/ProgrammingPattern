#pragma once
#include <iostream> //<> = 좁음, 같은 폴더에 있는거만 추적
#include "MGameLoop.hpp" //"" = 주소 기반 추적

int main()
{
	MuSoeun::MGameLoop gameLoop;
	gameLoop.Run();
}