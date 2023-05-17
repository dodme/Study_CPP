#include <iostream>
#include <string>
using namespace std;

int Solution(int n)
{
	int result = 0;

	string str = to_string(n);

	for (int i = 0; i < str.length(); i++)
	{
		result += n % 10;
		n /= 10;
	}

	return result;
}

int main()
{
	int n = 0;

	cin >> n;

	cout << Solution(n) << endl;

	return 0;
}