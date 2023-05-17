#include <iostream>
using namespace std;

// 클래스?
/// > 구조체와 굉장히 유사합니다.

// 단! 구조체는 값형식, 클래스는 참조형식이다.

//객체지향 프로그래밍 언어의 3대 특성
/// 은닉성 : 코드에 대한 접근가능 여부를 판별한다.
/// 상속성 : To be Continue...
/// 다형성 : 다양한 정보를 가지고있다.

class Sample
{
public:
	// 인스턴스필드
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