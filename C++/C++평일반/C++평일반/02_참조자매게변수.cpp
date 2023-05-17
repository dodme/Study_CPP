#include <iostream>
using namespace std;

void Plus(int& a, int value)
{
	a += value;
}

int main()
{
	int num = 10;

	Plus(num, 20);
	cout << num << endl;


	return 0;
}

// 문제!
/// Swap함수를 정의하세요.
/// 반드시 참조자를 이용할것
/// A = 10, B = 20;
/// Swap(A, B);
/// B = 20, A = 10;