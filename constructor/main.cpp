#include <iostream>

class Entity
{
public:
	float X, Y; // 쓰레기값 (내 컴파일러 환경은 0으로 나오긴 했음)
	/*void Init()
	{
		X = 0.0f;
		Y = 0.0f
	}*/
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}
	Entity(float x, float y)
	{
		X = x, Y = y;
	}
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

int main()
{
	Entity e; // e.Init(); // 추가를 한 거다. 근데 이렇게 하면 너무 귀찮으니 생성자를 사용하는 것이다.
	std::cout << e.X << std::endl;
	e.Print();
	Entity e1(2.4f, 3.6f);
	e1.Print();
	std::cin.get();
}



/*
 * 실제로 6번 코드 내용 warning도 나오게 찍어보면 이렇게 나오긴 함(초기화가 되지 않았다)
 * [smsc@vsmsc constructor]$ g++ -Wall -o main main.cpp
main.cpp: In function ‘int main()’:
main.cpp:17:24: warning: ‘e.Entity::X’ is used uninitialized [-Wuninitialized]
   17 |         std::cout << e.X << std::endl;
      |                        ^
main.cpp:16:16: note: ‘e’ declared here -----> 그 변수는 여기에서 사용되었어~
   16 |         Entity e;
      |
*/
