#include <iostream>

class Entity
{
public:
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player : public Entity
{
public:
	const char* Name;
	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};
int main()
{
	std::cout << sizeof(Entity) << std::endl; // float 두 개(32비트든 64비트든 각 4 바이트)
	std::cout << sizeof(Player) << std::endl; // float 두 개 + Name 포인터 변수 (포인터 변수는 64비트에서 8바이트)
	Player player;
	player.Move(5, 5);
	player.X = 2;
	std::cin.get();
}
