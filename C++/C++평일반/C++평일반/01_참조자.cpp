#include <iostream>
using namespace std;

int main()
{
	// 하나의 메모리에 두개의 별명을 붙여주는것
	int num = 10;

	int& ref = num;

	ref += 10;

	cout << "num : " << num << endl;
	cout << "ref : " << ref << endl;



	return 0;
}