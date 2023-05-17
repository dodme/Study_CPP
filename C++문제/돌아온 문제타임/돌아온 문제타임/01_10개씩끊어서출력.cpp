#include <iostream>
using namespace std;

int main()
{
	//char str[100] = { 0 };
	//int count = 0;

	//cout << "알파벳을 입력하세요" << endl;
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
	//cout << "끝" << endl;

	char str[11];

	while (true)
	{
		cin.get(str, 11);
		if (!cin.gcount())
			// cin.gcount() : 입력버퍼에 값이 있다면 true 없다면 false
		{
			break;
		}
		cout << str << endl;
	}

	return 0;
}