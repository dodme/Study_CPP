#include <iostream>
using namespace std;

int main()
{
	// �ϳ��� �޸𸮿� �ΰ��� ������ �ٿ��ִ°�
	int num = 10;

	int& ref = num;

	ref += 10;

	cout << "num : " << num << endl;
	cout << "ref : " << ref << endl;



	return 0;
}