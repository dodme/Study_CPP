#include <iostream>
using namespace std;

int main()
{
	// �����Լ�

	[] () -> void 
	{
		cout << "����" << endl;
	}();

	int a = 10;
	int b = 20;

	cout << "10 + 20 = " << [a, b]() -> int {return a + b; }() << endl;



	return 0;
}