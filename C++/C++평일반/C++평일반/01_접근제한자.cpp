#include <iostream>
using namespace std;

// ����������
/// > �ڵ忡 ���� ���м��� ����
/// > ����� ���� ���ٰ��� ���θ� �Ǻ��մϴ�.

//					Ŭ���� �ܺ�	Ŭ���� ����
/// private		:		X			O
/// protected	:	��ӿ���	To be Continue...
/// public		:		O			O

class Sample
{
private:
	int pri_Num;

	void Pri_Method()
	{
		cout << pri_Num << endl;
	}
public:
	int pub_Num;

	void Pub_Method()
	{
		cout << pub_Num << endl;
	}
};

int main()
{
	Sample* s1 = new Sample();



	delete s1;
	s1 = nullptr;



	return 0;
}