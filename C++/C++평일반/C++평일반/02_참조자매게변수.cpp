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

// ����!
/// Swap�Լ��� �����ϼ���.
/// �ݵ�� �����ڸ� �̿��Ұ�
/// A = 10, B = 20;
/// Swap(A, B);
/// B = 20, A = 10;