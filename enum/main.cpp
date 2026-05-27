#include <iostream>
/* 오로지 0, 1, 2 중 하나
int A = 0;
int B = 1;
int C = 2;
*/

enum Example : unsigned char
{
	A = 5, B, C // 하나씩 올라감
};

int main()
{
	Example val = B;

	if (val == B)
	{
		
	}
	std::cin.get();
}
