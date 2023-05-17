#include <iostream>
using namespace std;

namespace Test
{
	void Sample()
	{
		std::cout << "뀨?" << std::endl;
	}
}

int main()
{
	// :: -> 스코프연산자/ 범위지정연산자

	std::cout << "Hello World!" << std::endl;
	cout << "Hello World!" << endl;
	Test::Sample();


	return 0;
}