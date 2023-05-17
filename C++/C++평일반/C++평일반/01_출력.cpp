#include <iostream> //  .h를 생략한다!

int main()
{
	std::cout << "Hello World" << std::endl;

	// cout : 표준출력 키워드
	// endl : 개행 == '\n'
	// <<   : 병합연산자

	int inputNum = 0;
	std::cin >> inputNum;
	std::cout << inputNum << std::endl;

	std::cout << "이상효" << std::endl;


	return 0;
}

// 문제!
// 자신의 이름을 출력하세요