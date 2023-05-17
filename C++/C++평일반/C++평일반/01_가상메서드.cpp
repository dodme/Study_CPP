#include <iostream>
using namespace std;

// ����޼��� overriding / override
// virtual

// ����޼����?
/// > ��ü�� �޼��� ȣ���ÿ� ȣ������� ������ �ڷ��� �����̾��� ������
///   ������ ���� ȣ���� ������ �����.
///   ���� �̷��� ������ Ÿ���ϱ����� ���� ����

/// > ���� : �θ� �ִ� �޼��带 �ڽ�Ŭ�������� ������ �ϴ°��� ����ϴ°�

// > �޼��� �������̵��� ����
/// > �޼��� �̸��� �ŰԺ��� ����� ��ġ�Ұ�
/// > �θ��� �޼��忡 virtual�� ���� �Ǿ� ������
/// > �ڽ�Ŭ���� �ʿ��� �������̵� �Լ��ΰ��� �ǹ��ϱ�����
///   �Լ� �ڿ� override�� �ٿ� ����Ѵ�

class SampleBase
{
public:
	virtual void Method()
	{
		cout << "Base" << endl;
	}
};

class SampleChild : public SampleBase
{
public:
	void Method() override
	{
		cout << "Child" << endl;
	}
};

int main()
{
	SampleBase* s1 = new SampleChild();

	s1->Method();

	delete s1;
	s1 = nullptr;


	return 0;
}