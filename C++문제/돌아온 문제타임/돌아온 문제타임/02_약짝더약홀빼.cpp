#include <iostream>
using namespace std;

int main()
{
	int left = 0, right = 0;

	
	int temp = 0;
	int count = 0;
	int solution = 0;

	cout << "두개의 정수를 입력하세요" << endl;
	cin >> left;
	cin >> right;

	if (left > right)
	{
		temp = left;
		left = right;
		right = temp;
	}

	for (int i = left; i <= right; i++)
	{
		count = 0;
		for (int j = 1; j <= left; j++)
		{
			if (left % j == 0)
			{
				count++;
			}
		}
		
		if (count % 2 == 0)
		{
			solution += left;
		}
		else
		{
			solution -= left;
		}
	}

	cout << endl;
	cout << endl;
	cout << endl;

	cout << solution << endl;

	return 0;
}