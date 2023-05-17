#include <iostream>
using namespace std;

int Solution(int a, int b)
{
	if (a > b)
	{
		for (int i = (b + 1); i <= a; i++)
		{
			b += i;
		}
		return b;
	}
	else
	{
		for (int j = (a + 1); j <= b; j++)
		{
			a += j;
		}
		return a;
	}
}

int main()
{
	int a = 0;
	int b = 0;

	cout << "두 정수를 입력하세요." << endl;
	cin >> a >> b;

	cout << Solution(a, b) << endl;




	return 0;
}