#include <iostream>
using namespace std;

// ���?
/// > �θ�Ŭ������ �ִ� ������ �ڽ�Ŭ�������� �����ִ°�
// �ڵ��� ���꼺, �ڵ��� ��Ȱ�뼺�� ���̱����� ����մϴ�.

// �θ�Ŭ����, ����Ŭ����, ����Ŭ����, ���Ŭ����, ����Ŭ����, BaseClass
// �ڽ�Ŭ����, ����Ŭ����, ����Ŭ����, �Ļ�Ŭ����, ����Ŭ����, ChildClass

// �θ�Ŭ������ ���� �մϴ�.
class SampleBase
{
public:
	int num;

	void BaseMethod()
	{
		cout << "�Ҷ�ī" << endl;
	}
};

// �ڽ�Ŭ������ �����մϴ�.
class SampleChild : public SampleBase
{
public:
	int child_Num;

	void ChildMethod()
	{
		num = 10;
		BaseMethod();
	}
};

int main()
{
	SampleBase* base = new SampleBase();

	// base->ChildMethod(); X

	delete base;
	base = nullptr;

	SampleChild* child = new SampleChild();

	child->BaseMethod();

	delete child;
	child = nullptr;


	return 0;
}