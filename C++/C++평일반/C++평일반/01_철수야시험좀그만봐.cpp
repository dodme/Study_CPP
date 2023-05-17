#include <iostream>
using namespace std;

// 총점
int Total(int kor, int eng, int math)
{
	return kor + eng + math;
}

//평균
int Average(int total, int subject)
{
	return total / subject;
}

//평균
float Average(int total, float subject)
{
	return total / subject;
}

//최고점수
int HighScore(int kor, int eng, int math)
{
	kor = (kor > eng) ? kor : math;
	return (kor > math) ? kor : math;
}

int main()
{
	int kor, eng, math = 0;

	cout << "철수의 국어점수를 입력하세요." << endl;
	cin >> kor;
	cout << "철수의 영어점수를 입력하세요." << endl;
	cin >> eng;
	cout << "철수의 수학점수를 입력하세요." << endl;
	cin >> math;

	int total = 0;

	total = Total(kor, eng, math);
	cout << "총점은" << Total(kor, eng, math) << "입니다." << endl;
	cout << "평균은" << Average(total, 3.0f) << "입니다." << endl;
	cout << "최고점수는" << HighScore(kor, eng, math) << "입니다." << endl;





	return 0;
}