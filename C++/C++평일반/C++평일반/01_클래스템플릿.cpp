#include <iostream>
using namespace std;

// Ŭ�������ø�
/// > Ŭ���� ���ο��� ���ø��� ����ϰڴٴ� �ǹ�

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