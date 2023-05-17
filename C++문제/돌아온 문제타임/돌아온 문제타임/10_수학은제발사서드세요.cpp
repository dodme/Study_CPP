#include <iostream>
using namespace std;

int main()
{
	int a = 0, r = 0, n = 0, mod = 0, temp = 0;

	cin >> a >> r >> n >> mod;

	for (int i = 0; i < n; i++)
	{
		temp += a;
		a *= r;
	}

	cout << temp - mod;

	return 0;
}