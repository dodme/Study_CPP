#include <iostream>
#include <combaseapi.h>
using namespace std;

// 인터페이스
/// > 순수가상메서드로만 이루어진 클래스 비스무리한거
/// > 인스턴스화가 불가능 : 순수가상메서드의 정의부가 불완전하기떄문에 메모리 생성이 불가능
/// interface
/// combaseapi.h

interface ISample
{
	virtual void Method() abstract;
};

interface ISample2
{
	virtual void Method2() abstract;
};

// 부모클래스에서 추상메서드가 정의되지 않았다면 자식쪽에서라도 반드시 구현해야한다
class Sample : public ISample, ISample2
{
	// ISample을(를) 통해 상속됨
	virtual void Method() override
	{

	}

	// ISample2을(를) 통해 상속됨
	virtual void Method2() override
	{

	}
};

int main()
{
	// 코드 작성은 가능하지만 실행은 불가능!
	//ISample s1;
	//ISample* s2 = new ISample();
	//s2->Method();
	//
	//delete s2;
	//s2 = nullptr;


	return 0;
}