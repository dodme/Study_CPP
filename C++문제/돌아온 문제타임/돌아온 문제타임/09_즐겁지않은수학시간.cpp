#include <iostream>
using namespace std;

int main()
{
	int N = 0, L = 0;
	int temp = 0;

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j <= L; j++)
		{
			temp += j;
		}

		if (temp == N)
		{
			for (int j = 0; j <= L; j++)
			{
				cout << i;
				i++;
			}
			return 0;
		}

		temp = 0;
	}


	return 0;
}