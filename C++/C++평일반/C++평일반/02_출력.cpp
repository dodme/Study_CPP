#include <iostream>
using namespace std;

namespace Test
{
	void Sample()
	{
		std::cout << "��?" << std::endl;
	}
}

int main()
{
	// :: -> ������������/ ��������������

	std::cout << "Hello World!" << std::endl;
	cout << "Hello World!" << endl;
	Test::Sample();


	return 0;
}