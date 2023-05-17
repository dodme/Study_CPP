#include <iostream>
using namespace std;

int main()
{
	// 무명함수

	[] () -> void 
	{
		cout << "응애" << endl;
	}();

	int a = 10;
	int b = 20;

	cout << "10 + 20 = " << [a, b]() -> int {return a + b; }() << endl;



	return 0;
}