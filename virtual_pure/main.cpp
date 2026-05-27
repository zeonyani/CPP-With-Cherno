#include <iostream>
#include <string>
class Printable
{
	public:
		virtual std::string GetClassName() = 0; // 순수 가상함수를 선언하는 방식
		/* 추상 클래스 -> 하나 이상의 순수 가상 함수를 포함하는 클래스
		 * 객체 생성 불가(개념적인 정의만 담고 있음)
		 * 결국 main 함수에서 객체 만들 때 Entity 객체를 만들 수 없고 GetName 을 실제로 구현한
		 * Player 같은 파생 클래스의 객체만 생성할 수 있음
		 * 실제로 C++ 에는 "인터페이스" 키워드가 없지만 "순수 가상 함수" 가 이 역할을 대신
		 * => 구현은 강제하지 않되 무엇을 해야하는지 규격만 정의하는 것!
		 */
};

class Entity : public Printable
{
	public:
		virtual std::string GetName() { return "Entity"; }
		std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
	private:
		std::string m_Name;
	public:
		Player(const std::string& name)
			: m_Name(name) {}

		std::string GetName() override { return m_Name; }
		std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* e)
{
	std::cout << e->GetName() << std::endl;
}
/* class A 의 목적
 * 기존에는 Entity, Player 처리 각각인데 Printable이라는 공통 인터페이스(실제로는 순수 가상 함수)로
 * Print(Printable* obj) 는 함수 A 클래스가 어떻게 구현되거나 무슨 멤버 변수가 있는지 모르고 "오로지"
 * GetClassName 함수가 있다는 것만 알고 있고 이를 호출 (추후 기능 확장해도 기존 코드 수정 필요가 없음)
 */
class A : public Printable
{
	public:
		std::string GetClassName() override { return "A"; }
		// 39번 주석 내용 추가 해당 윗 줄이 없으면 main에서 new A() 같은 걸 못함
};
void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}
int main()
{
	Entity* e = new Entity();
	// PrintName(e);

	Player* p = new Player("hyang");
	// PrintName(p);

	Print(e);
	Print(p);
	Print(new A());

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
