#include <iostream>
using namespace std;

int main()
{
	//char str[100] = { 0 };
	//int count = 0;

	//cout << "���ĺ��� �Է��ϼ���" << endl;
	//cin.getline(str, 100, '\n');

	//cout << endl;
	//cout << endl;
	//cout << endl;

	//for (int i = 0; i < (strlen(str) / 10 + 1); i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		cout << str[count];
	//		count++;
	//	}
	//	cout << endl;
	//}
	//
	//cout << "��" << endl;

	char str[11];

	while (true)
	{
		cin.get(str, 11);
		if (!cin.gcount())
			// cin.gcount() : �Է¹��ۿ� ���� �ִٸ� true ���ٸ� false
		{
			break;
		}
		cout << str << endl;
	}

	return 0;
}