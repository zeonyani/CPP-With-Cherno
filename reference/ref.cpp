#include <iostream>
#define LOG(x) std::cout << x << std::endl
/* 방법1 포인터
 * 주의 *val++ 이 아닌 (*val)+++;
 * 사유: val에 들어가는 값에 하나를 증가하길 바라니까
void Increment(int* val)
{
	(*val)++;
}
*/

/* 방법2 */
void Increment(int& val)
{
	val++;
}

int main(void)
{
    int a = 5;
	Increment(a);
	LOG(a);	
	std::cin.get();
}
