#include <iostream>
using namespace std;

// Ŭ����?
/// > ����ü�� ������ �����մϴ�.

// ��! ����ü�� ������, Ŭ������ ���������̴�.

//��ü���� ���α׷��� ����� 3�� Ư��
/// ���м� : �ڵ忡 ���� ���ٰ��� ���θ� �Ǻ��Ѵ�.
/// ��Ӽ� : To be Continue...
/// ������ : �پ��� ������ �������ִ�.

class Sample
{
public:
	// �ν��Ͻ��ʵ�
	int num;
	float f_Num;

	void Method()
	{
		cout << "Hello World!" << endl;
	}
};

int main()
{
	Sample* s1 = new Sample();

	s1->num = 10;
	delete s1;
	s1 = nullptr;

	return 0;
}