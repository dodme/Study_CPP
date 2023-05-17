#include <iostream>
using namespace std;

//void DrawStar(int num, int goal)
//{
//	for (int i = 1; i <= goal; i++)
//	{
//		for (int j = 1; j <= num; j++)
//		{
//			if ((i <= (num / 3) || i > (num - (num / 3)))
//				|| (j <= (num / 3) || j > (num - (num / 3))))
//				cout << "*";
//			else
//				cout << " ";
//		}
//		cout << endl;
//	}
//	if (num != goal)
//		DrawStar(num * 3, goal);
//}

void Solution(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
	{
		cout << " ";
	}
	else
	{
		if (n / 3 == 0)
			cout << "*";
		else
			Solution(i, j, n / 3);
	}
}

int main()
{
	//DrawStar(3, 27);

	int inputNumber = 0;
	cin >> inputNumber;

	for (int i = 0; i < inputNumber; i++)
	{
		for (int j = 0; j < inputNumber; j++)
		{
			Solution(i, j, inputNumber);
		}
	}

	return 0;
}