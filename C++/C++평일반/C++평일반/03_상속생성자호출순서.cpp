#include <iostream>
using namespace std;

// ���߻��? O
// ��ø���? O

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

// ����!
/// ĳ������ ������ ������ �����մϴ�.
/// �̸�, ����
/// Warrior, Archer 2���� ������ �ֽ��ϴ�.
/// Warrior�� Def
/// Archer�� Eva

// �� �� ���� ���