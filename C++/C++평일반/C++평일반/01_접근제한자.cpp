#include <iostream>
using namespace std;

// 접근제한자
/// > 코드에 대한 은닉성을 위해
/// > 멤버에 대한 접근가능 여부를 판별합니다.

//					클래스 외부	클래스 내부
/// private		:		X			O
/// protected	:	상속에서	To be Continue...
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