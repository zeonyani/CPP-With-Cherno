#include <iostream>
#define LOG(x) std::cout << x << std::endl
/* 계속 반복해서 코드를 만들기 싫으니깐 - 하나의 클래스로 만들자! */
class Player
{
public:
	int x, y;
	int speed;
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
	
};

// 이렇게 함수 정의를 밖에서 할 수 있지만...
/*
void Move(Player& player, int xa, int ya)
{
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}
*/

int main(void)
{
    Player player;
	// player.x = 5; // private 이라서 접근을 못하니까 public으로 해줬어야 외부에서 접근 가능
	player.Move(1, -1);

	std::cin.get();
}
/* struct 와의 차이
 * struct 는 default 가 public 이라는 거 말곤 없음
 * cherno는 struct 사용 시 절대 상속은 안한다 함(개취)
 */
