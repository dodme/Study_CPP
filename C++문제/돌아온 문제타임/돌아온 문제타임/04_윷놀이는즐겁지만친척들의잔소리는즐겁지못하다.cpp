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
		cout << "��" << endl;
		break;
		
	case 1:
		cout << "��" << endl;
		break;

	case 2:
		cout << "��" << endl;
		break;

	case 3:
		cout << "��" << endl;
		break;

	case 4:
		cout << "��" << endl;
		break;

	default:
		cout << "������..?" << endl;
		break;
	}

	return 0;
}