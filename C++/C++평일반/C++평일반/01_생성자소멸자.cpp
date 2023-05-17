#include <iostream>
using namespace std;

// 생성자?
/// > 객체의 메모리가 생성될 당시에 정보전달 역할을 하는 특수 메서드

// 소멸자?
/// > 객체의 메모리가 해제될때 호출되는 메서드

// 생성자와 소멸자 작성규칙
/// > 접근제한자는 public 이어야 하며,
/// > 반환형식을 지정하지 않고, 클래스의 이름과 일치한 이름을 갖는다.
/// > 소멸자엔 '~'클래스이름 을 붙인다.

class Sample
{
public :
	int num;
	int* p = &num;

	Sample() { } // 기본 생성자

	~Sample() { } // 기본 소멸자
	
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
	//	cout << "생성자" << endl;
	//}
	//
	//~Sample()
	//{
	//	cout << "소멸자" << endl;
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