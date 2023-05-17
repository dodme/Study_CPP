#include <iostream>
using namespace std;

// ���� ���� �޼���
/// > ���� : �θ��ִ� �޼��带 �ڽ�Ŭ�������� "�ݵ��!" ������ �ؾ� �ϴ°�
// virtual ��ȯ���� �Լ��̸�() abstract;
// virtual ��ȯ���� �Լ��̸�() = 0;

// �߻� Ŭ������ Ư¡
/// > ���� ���� �޼��带 1�� �̻� ����� ������ �ִ� Ŭ����
/// > �ν��Ͻ�ȭ�� �Ұ����ϴ�.
/// > �ݵ�� ����� ���ؼ��� ����Ѵ�.

class SampleBase
{
public:
	virtual void PureMethod() abstract;
	void Print()
	{
		cout << "Hello World!" << endl;
	}
};

class SampleChild : public SampleBase
{
	// SampleBase��(��) ���� ��ӵ�
	virtual void PureMethod() override
	{
		cout << "������ ����" << endl;
	}
};

int main()
{
	SampleBase* s1 = new SampleChild();



	return 0;
}