#include <iostream>>
using namespace std;

int main()
{
	int num = 0;

	cout << "16진법 A ~ F사이의 값을 입력하세요." << endl;
	cin >> hex >> num;

	if (num > 16 || num < 10)
	{
		cout << "잘못된 값입니다." << endl;
		return 0;
	}

	for (int i = 1; i < 16; i++)
	{
		cout << hex << num << " X " << i << " = " << num * i << endl;
	}

	
	return 0;
}