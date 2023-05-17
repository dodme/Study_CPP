#include <iostream>
using namespace std;

// 동적할당 < - > 정적할당

// 동적 메모리 할당 키워드 : new
// 동적 메모리 해제 키워드 : delete

// 메모리영역(RAM) 4단계
//----------------------
// Code Area(코드영역)		: 운영체제가 관리하는 메모리
// Data Area(데이터영역)		: 개발자가 임의로 관여할수 없다.
/// << MessageQueue(함수호출메모리)
// Stack Area(스택영역)		: 정적메모리
/// << static
/// << 정적 메모리의 최대범위를 초과했을때 Stakc Overflow가 발생한다.
// Heap Area(힙영역)			: 동적메모리
/// << new

int main()
{
	int* p = new int;
	delete p;
	p = nullptr;


	return 0;
}