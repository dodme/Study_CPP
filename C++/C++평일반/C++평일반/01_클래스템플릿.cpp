#include <iostream>
using namespace std;

// 클래스템플릿
/// > 클래스 내부에서 템플릿을 사용하겠다는 의미

template<class T>
class Sample
{
private:
	T value;

public:
	T Add(T a, T b)
	{
		return a + b;
	}

	T GetValue() { return value; }
	void SetValue(T value1) { value = value1; }
};

int main()
{
	Sample<int>* s1 = new Sample<int>();

	delete s1;
	s1 = nullptr;



	return 0;
}