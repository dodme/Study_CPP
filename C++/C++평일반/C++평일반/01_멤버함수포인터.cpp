#include <iostream>
using namespace std;

// 함수포인터
/// > 

class Sample
{
public:
	void SampleMethod()
	{
		cout << "Method" << endl;
	}
	void SampleMethod(int a)
	{
		cout << "Method A" << endl;
	}
	void SampleMethod(int a, int b)
	{
		cout << "Method A B" << endl;
	}

};

int main()
{
	Sample sample;
	//void (*s1)() = Function;

	void (Sample:: * s1)() = Sample::SampleMethod;

	(sample.*s1)();

	return 0;
}