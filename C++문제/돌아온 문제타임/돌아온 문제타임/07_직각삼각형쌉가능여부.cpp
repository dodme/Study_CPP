#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arrNum[3] = { 0 };

	cin >> arrNum[0] >> arrNum[1] >> arrNum[2];

	sort(arrNum, arrNum + 3);

	if (pow(arrNum[2], 2) == (pow(arrNum[0], 2) + pow(arrNum[1], 2)))
		cout << "Right" << endl;
	else
		cout << "Wrong" << endl;


	return 0;
}