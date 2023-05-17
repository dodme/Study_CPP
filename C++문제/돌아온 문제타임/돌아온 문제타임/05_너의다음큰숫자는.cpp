#include <iostream>
using namespace std;

int ToBinary(int value)
{
	int count = 0;

	while (value != 0)
	{
		if (value % 2 == 1)
			count++;
	}

	return count;
}

int Solution(int n)
{
	int origin = ToBinary(n);
	int answer = n;

	while (true)
	{
		answer++;
		if (ToBinary(answer) == ToBinary(n))
			return answer;
	}
}

int main()
{
	cout << Solution(78) << endl;

	/*int num = 0;
	int temp = 0;
	int count1 = 0;
	int count2 = 0;
	
	cin >> num;

	temp = num;
	while ((temp / 2) != 0 && (temp / 2) != 1)
	{
		if (temp % 2 == 1)
		{
			count1++;
		}
		temp = num / 2;
		if ((temp / 2) == 1)
			count1++;
	}

	while (count2 != count1)
	{
		num++;
		temp = num;
		while ((temp / 2) != 0 && (temp / 2) != 1)
		{
			if (temp % 2 == 1)
			{
				count2++;
			}
			temp = num / 2;
		}
		count2 = 0;
	}

	cout << num;*/

	return 0;
}