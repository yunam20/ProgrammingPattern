#include <iostream>
#include <vector> //list¶û ¶È°°À½
#include <string>

namespace MuSoeun
{
	class Scene
	{
		int width;
		int height;
		std::vector<Object>* ObjList;
		
		//screenBuf[width + (width * height)];
		
		char* screenBuf;
		void InitScreenBuf()
		{
			screenBuf = new char[(width+1) * (height+5)];
			for (int i; i < height; i++)
			{
				screenBuf[(width + 1) + (width + 1) * i] = '\n';
			}
			screenBuf[(width + 1) + (width + 1) * (height-1) - 1] = '\n'
		}

		void ReleaseScreenBuf()
		{
			if (screenBuf != nullptr)
			{
				delete(screenBuf);
			}
		}

		void DrawScreenBuf()
		{
			std::cout << screenBuf;
		}
	};

	class Object
	{
		void Render();
	};

	class Component //Unity MonoBehavior
	{
		void Start();
		void Update();
	};
}

int main()
{
	while (1)
	{

	}
}