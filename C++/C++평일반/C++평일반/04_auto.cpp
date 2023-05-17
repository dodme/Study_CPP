#include <iostream>
using namespace std;

//타입추론
/// > 자료형을 유추하는것

//auto
/// > 컴파일 단계에서 자료형을 (초기화된 값으로) 결정지어 주는것


int main()
{
	auto value = 10;

	cout << value << endl;


	return 0;
}