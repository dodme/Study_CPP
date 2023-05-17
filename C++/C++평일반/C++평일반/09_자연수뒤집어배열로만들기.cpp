#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;

	string str = to_string(n);

	for (int i = str.length() - 1; i >= 0; i--)
		cout << str[i];


	return 0;
}