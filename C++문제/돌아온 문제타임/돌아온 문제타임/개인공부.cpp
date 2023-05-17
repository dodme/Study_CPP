#include <iostream>
using namespace std;

int main()
{
	int lottos[6] = { 0 };

	int win_number[6] = { 0 };

	int result[2] = { 0 };

	for (int i = 0; i < sizeof(lottos); i++)
	{
		while (lottos[i] > 45 || lottos[i] <= 0)
		{
			cout << "로또 번호를 입력하세요 : ";
			cin >> lottos[i];
			cout << endl;
			if (lottos[i] > 45 || lottos[i] <= 0)
			{
				cout << "잘못 입력하였습니다." << endl;
			}
		}
	}

	for (int i = 0; i < sizeof(win_number); i++)
	{
		while (win_number[i] > 45 || win_number[i] <= 0)
		{
			cout << "당첨 번호를 입력하세요 : ";
			cin >> win_number[i];
			cout << endl;
			if (win_number[i] > 45 || win_number[i] <= 0)
			{
				cout << "잘못 입력하였습니다." << endl;
			}
		}
	}

	for (int i = 0; i < sizeof(win_number); i++)
	{
		for (int j = 0; j < sizeof(lottos); i++)
		{
			if (lottos[j] == win_number[i])
				result[0]++;
		}
	}

	result[1] = result[0];

	for (int i = 0; i < sizeof(lottos); i++)
	{
		if (lottos[i] == 0)
			result[1]++;
	}

	cout << "[" << result[1] << ", " << result[2] << "]" << endl;

	return 0;
}
