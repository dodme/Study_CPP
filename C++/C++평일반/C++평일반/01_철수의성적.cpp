#include <iostream>
using namespace std;

int Sum(int kor, int eng, int math);
float Avg(int kor, int eng, int math);
int Max(int kor, int eng, int math);

int main()
{
	cout << "�����";
	int kor = 0;
	cin >> kor;

	cout << "�����";
	int eng = 0;
	cin >> eng;

	cout << "���м���";
	int math = 0;
	cin >> math;

	cout << endl;
	cout << endl;
	cout << endl;

	cout << Sum(kor, eng, math) << endl;
	cout << Avg(kor, eng, math) << endl;
	cout << Max(kor, eng, math) << endl;
	

	return 0;
}

int Sum(int kor, int eng, int math)
{
	return (kor + eng + math);
}

float Avg(int kor, int eng, int math)
{
	return Sum(kor, eng, math) / 3.0f;
}

int Max(int kor, int eng, int math)
{
	int max = (kor > eng) ? kor : eng;
	return (max > math) ? max : math;
}
