#include <iostream>

class Entity
{
public:
	float X, Y;
	Entity()
	{
		std::cout << "make entity" << std::endl;
		X = 0.0f;
		Y = 0.0f;
	}
	Entity(float x, float y)
	{
		X = x, Y = y;
	}
	~Entity() // 소멸자
	{
		std::cout << "destroy entity" << std::endl;
	}
	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};

void Function()
{
	Entity e; // 29줄 끝나면 바로 생성자 호출
	e.Print(); // Print() 호출
} // 소멸자 호출(객체 e가 사라지는 순간) -> main() 함수로 돌아온다.

int main()
{
	Function();
	std::cin.get();
}
