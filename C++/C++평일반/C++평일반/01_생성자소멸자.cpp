#include <iostream>
using namespace std;

// ������?
/// > ��ü�� �޸𸮰� ������ ��ÿ� �������� ������ �ϴ� Ư�� �޼���

// �Ҹ���?
/// > ��ü�� �޸𸮰� �����ɶ� ȣ��Ǵ� �޼���

// �����ڿ� �Ҹ��� �ۼ���Ģ
/// > ���������ڴ� public �̾�� �ϸ�,
/// > ��ȯ������ �������� �ʰ�, Ŭ������ �̸��� ��ġ�� �̸��� ���´�.
/// > �Ҹ��ڿ� '~'Ŭ�����̸� �� ���δ�.

class Sample
{
public :
	int num;
	int* p = &num;

	Sample() { } // �⺻ ������

	~Sample() { } // �⺻ �Ҹ���
	
	Sample(int num)
	{
		p = new int;
		this->num = num;
	}

	~Sample()
	{
		delete p;
		p = nullptr;
	}

	//Sample()
	//{
	//	cout << "������" << endl;
	//}
	//
	//~Sample()
	//{
	//	cout << "�Ҹ���" << endl;
	//}

	void PrintNum()
	{
		cout << num << endl;
	}
};

int main()
{
	Sample* s1 = new Sample();


	delete s1;
	s1 = nullptr;


	return 0;
}