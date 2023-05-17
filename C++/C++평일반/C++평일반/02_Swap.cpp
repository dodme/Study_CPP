#include <iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int A = 10;
	int B = 20;
	Swap(A, B);

	cout << "A : " << A << endl;
	cout << "B : " << B << endl;

	return 0;
}