#include <iostream>
using namespace std;

int Solution(int arrA[], int arrB[])
{
	int count = 0;
	int size = (sizeof(arrA));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arrB[i] > arrA[j] && arrA[j] != 0)
			{
				count++;
				arrA[j] = { 0 };
				break;
			}
		}
	}

	return count;
}

int main()
{
	int arrA[4] = { 5, 1, 3, 7 };
	int arrB[4] = { 2, 2, 6, 8 };

	cout << Solution(arrA, arrB) << endl;

	return 0;
}