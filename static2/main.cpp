#include <iostream>

struct Entity
{
	// int x, y;
	static int x, y; // 얘네들을 static으로 만드는 순간 -> 링크 에러 (Entity::x 코드가 필요)
	/* 다른 파일에서 "이 파일에서만 쓸거야" 라고 하는 static 키워드와 다르다.
	 * 여기에서 쓰는 static 키워드는 클래스나 구조체 내부에서 static 변수를 사용하는 것으로
	 * 객체 메모리 안에는 존재하지 않고 프로그램의 데이터 영역에 "딱 하나" 존재
	 * => 객체별로 따로 만들지 말고 설계도 레벨에서 "단 한개만" 공유하겠다는 의미
	 */
	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x; // struct 내 static 변수로 만든 경우
int Entity::y;

int main()
{
	Entity e;
	e.x = 2; // static 으로 쓰는 경우 Entity::x = 2; 이런 식으로 써야 함. -> static 은 "객체의 것이 아님"
	// 또한 가독성을 위함. "이것만 바뀌는 게 아니라 전체가 다 바뀌어서 위험하겠네"를 알리기!
	e.y = 3;

	//Entity e1 = {5, 8};
	Entity e1;
	e1.x = 5;
	e1.y = 8; // "단 한개" 라서 실제 Print() 함수 호출 시 5, 8만 두 번 출력되는 것을 볼 수 있음
	
	e.Print();
	e1.Print();
	/* 결국 static 으로 정의했으면 객체의 것이 아니라 Entity::Print() 가 두 번 불리우는 꼴이라서
	 * 동일한 5, 8이 두 번 출력된 것이다.
	 * 물론 Print() 함수가 static 으로 선언되지 않더라도 결과 측면에서 차이는 없긴 하지만
	 * 변수가 static 인데 함수가 static 이 아니면 "이 객체를 통해 호출했다"를 보여주는 정도의 차이
	 * (데이터는 여전히 static)
	 * 더 나은 설계는 변수들이 전부 static 이면 함수도 static 으로 선언하는 것이 명확한 코드라 하겠다.
	 */
	std::cin.get();
}
