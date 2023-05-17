#include <iostream>
using namespace std;

// 다중상속? O
// 중첩상속? O

class A
{
public:
	A() { cout << "A" << endl; }
	~A() { cout << "~A" << endl; }
};

class B : public A
{
public:
	B() { cout << "B" << endl; }
	~B() { cout << "~B" << endl; }
};

class C : public B, public A
{
public:
	C() { cout << "C" << endl; }
	~C() { cout << "~C" << endl; }
};

int main()
{
	C* c = new C();

	delete c;
	c = nullptr;

	return 0;
}

// 숙제!
/// 캐릭터의 직업을 여러개 설정합니다.
/// 이름, 무기
/// Warrior, Archer 2개의 직업이 있습니다.
/// Warrior엔 Def
/// Archer엔 Eva

// 둘 다 정보 출력