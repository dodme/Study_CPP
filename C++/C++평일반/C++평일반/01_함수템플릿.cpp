#include <iostream>
using namespace std;

// 일반화
/// > 특수한 개념으로부터 공통된 개념으로 묶는것

// 일반화 프로그래밍
/// > 특수한 자료형으로부터 공통된 자료형으로 묶는것
/// > template<typename T> / template<class T>

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

int main()
{
	Print<int>(10);
	Print<float>(100.1f);
	Print<char>('A');


	return 0;
}