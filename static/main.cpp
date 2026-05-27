#include <iostream>

extern int s_Variable; // 외부랑 연결하겠다는 의미

void Function()
{
	
}

int main()
{
	std::cout << s_Variable << std::endl;
	std::cin.get();
}
