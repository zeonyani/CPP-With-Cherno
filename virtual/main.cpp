#include <iostream>
#include <string>

class Entity
{
	public:
		// std::string GetName() { return "Entity"; }
		virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
	private:
		std::string m_Name;
	public:
		Player(const std::string& name)
			: m_Name(name) {}

		std::string GetName() override { return m_Name; }
		// override 키워드를 넣지 않아도 정상 컴파일 되고 의도대로 동작한다
		// 그러나 override 키워드를 사용하는 이유는 "함수 시그니처가 미세하게 다를 때"
		// 예를 들어 부모 클래스에는 const 를 붙였다가 자식 클래스에서 const 를 뺀 경우
		// -> 동일한 함수가 아니라 "새로운 함수"로 인식되어 원인을 찾지 못하는 경우가 발생하게 된다.
		// 그래서 override 키워드를 통해 "컴파일러에게 시키는 검사"를 확인하게 하는 거!
};

void PrintName(Entity* e)
{
	std::cout << e->GetName() << std::endl;
}
int main()
{
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;

	Player* p = new Player("Hyang");
	std::cout << p->GetName() << std::endl;

	Entity* entity = p; // 이 부분에서 사실 Hyang이 출력되길 기대했다. 이미 만들어진 객체를 가리키니까
	// Entity 클래스의 GetName() 함수를 virtual 로 했더니 기대하던 "Hyang" 출력
	std::cout << entity->GetName() << std::endl;
	
	PrintName(e);
	PrintName(p);

	std::cin.get();
}

/*
 * 부모 타입의 포인터로 자식 객체를 다루면 부모 클래스의 동작만 강제되는데
 * 이러면 기대했던 "다형성"이 죽는다.
 * 그래서 virtual 을 활용
 *
 * "모든 객체를 다 일일이 알고 있는 게 아니기 떄문"에 부모타입으로 자식을 가리키는 경우가 있는 거다.
 */
