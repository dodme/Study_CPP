#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 템플릿의 특수화
template<>
const char* Add(const char* a, const char* b)
{
	const char* str = "문자열은 더할수 없습니다.";
	return str;
}

int main()
{
	cout << Add<const char*>("영희", "철수") << endl;
	cout << Add<int>(10, 20) << endl;


	return 0;
} 