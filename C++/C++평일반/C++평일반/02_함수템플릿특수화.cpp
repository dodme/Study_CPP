#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// ���ø��� Ư��ȭ
template<>
const char* Add(const char* a, const char* b)
{
	const char* str = "���ڿ��� ���Ҽ� �����ϴ�.";
	return str;
}

int main()
{
	cout << Add<const char*>("����", "ö��") << endl;
	cout << Add<int>(10, 20) << endl;


	return 0;
} 