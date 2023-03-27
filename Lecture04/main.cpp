#include <iostream>
#include <stdio.h>
#include <conio.h>

#define ESC 27

int main()
{
	int key = 0;
	while(true)
	{
		if (_kbhit())
		{
			key = _getch();
			if(key==ESC) break;
			else std::cout<<"fucking key"<<std::endl;
		}
	}

	std::cout<<"esc, fuck off"<<std::endl;
	return 0;
}
