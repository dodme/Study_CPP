#include <iostream>
using namespace std;

int main()
{
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;

	int sum = num1 + num2 + num3 + num4;

	switch (sum)
	{
	case 0:
		cout << "모" << endl;
		break;
		
	case 1:
		cout << "도" << endl;
		break;

	case 2:
		cout << "개" << endl;
		break;

	case 3:
		cout << "걸" << endl;
		break;

	case 4:
		cout << "윷" << endl;
		break;

	default:
		cout << "여긴어디..?" << endl;
		break;
	}

	return 0;
}