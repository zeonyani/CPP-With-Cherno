#include <iostream>
#include <string>

class Entity
{
	public:
		virtual std::string GetName() = 0; // 순수 가상 함수를 선언하는 방식
		/* 추상 클래스 -> 하나 이상의 순수 가상 함수를 포함하는 클래스
		 * 객체 생성 불가(개념적인 정의만 담고 있음)
		 * 결국 main 함수에서 객체 만들 때 Entity 객체를 만들 수 없고 GetName 을 실제로 구현한
		 * Player 같은 파생 클래스의 객체만 생성할 수 있음
		 */
};

class Player : public Entity
{
	private:
		std::string m_Name;
	public:
		Player(const std::string& name)
			: m_Name(name) {}

		std::string GetName() override { return m_Name; }
};

void PrintName(Entity* e)
{
	std::cout << e->GetName() << std::endl;
}
int main()
{
	Entity* e = new Entity();

	std::cin.get();
}

/*
 * 추후 궁금해진 사항 -> 왜 포인터 형으로 객체를 생성할까?
 * new 를 통해서 반환하는 것은 "포인터" 라서
 * 물론 참조자형태로도 가능하다
 * e.g. Player p("Hyang"); Entity ref = p; 이런 식으로(간접 참조)
 *
 * 자바는 모든 객체가 참조형이라서 그냥 new를 하는 거고 C++은 주소를 가리키는 포인터로 다형성을 구현한다.
 */ 
