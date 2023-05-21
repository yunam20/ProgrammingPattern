#pragma once
#include <iostream>
#include <vector>

namespace MuSoeun
{
	class Component
	{
	public:
		bool isStart = true;
		void Start()
		{
			while (isStart)
			{
				Update();
			}
		}
		void Update();
	};

	class Object
	{
	public:
		int x, y;
		char type;
		bool isActive = true;
		std::vector<Component> components;

		void Render(char* screenBuf, int width)
		{
			if (isActive)
			{
				// 해당 위치에 type 문자를 채워넣음
				screenBuf[y * (width + 1) + x] = type;
			}
		}
	};

	class Scene
	{
	public:
		int width;
		int height;
		std::vector<Object> ObjList;
		char* screenBuf;

		void AddObject(const Object& obj)
		{
			ObjList.push_back(obj);
		}

		void InitScreenBuf()
		{
			screenBuf = new char[(width + 1) * (height + 1)];
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					int index = j + (width + 1) * i;
					if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
						screenBuf[index] = 'X';  // 첫 줄, 마지막 줄, 첫 열, 마지막 열에 'X' 출력
					else
						screenBuf[index] = ' ';  // 나머지 부분은 공백으로 설정
				}
			}
			for (Object& obj : ObjList)
			{
				obj.Render(screenBuf, width);
			}
		}

		void ReleaseScreenBuf()
		{
			delete[] screenBuf;
			screenBuf = nullptr;
		}

		void DrawScreenBuf()
		{
			InitScreenBuf();
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width + 1; j++)
				{
					int index = j + (width + 1) * i;
					std::cout << screenBuf[index];
				}
				std::cout << std::endl;  // 한 줄 출력 후 개행
			}
			ReleaseScreenBuf();
		}
	};
}