#include <iostream>
using namespace std;

float Solution(int arr[], int size)
{
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		temp += arr[i];
	}
	return ((float)temp / size);
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int size = (sizeof(arr) / sizeof(arr[0]));

	cout << Solution(arr, size) << endl;

	return 0;
}