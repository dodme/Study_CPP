#include <iostream>
using namespace std;

// decltype -> declared type

int main()
{
	int num = 10;

	decltype(num) numClone = 100;

	cout << numClone << endl;


	return 0;
}