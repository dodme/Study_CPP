#include <iostream>
using namespace std;

int main()
{
	// 문자열을 입력받습니다.
	char str[256];

	cout << "당신이 좋아하는 프로그래밍언어는 무엇인가요~?" << endl;

	cin.getline(str, sizeof(str), '\n');
	// getline(문자열, 입력받을 문자의 최대수, 끝을 구분할 문자);
	cout << "입력한 값 : " << str << endl;


	return 0;
}