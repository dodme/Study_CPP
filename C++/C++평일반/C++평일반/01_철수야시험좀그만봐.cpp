#include <iostream>
using namespace std;

// ����
int Total(int kor, int eng, int math)
{
	return kor + eng + math;
}

//���
int Average(int total, int subject)
{
	return total / subject;
}

//���
float Average(int total, float subject)
{
	return total / subject;
}

//�ְ�����
int HighScore(int kor, int eng, int math)
{
	kor = (kor > eng) ? kor : math;
	return (kor > math) ? kor : math;
}

int main()
{
	int kor, eng, math = 0;

	cout << "ö���� ���������� �Է��ϼ���." << endl;
	cin >> kor;
	cout << "ö���� ���������� �Է��ϼ���." << endl;
	cin >> eng;
	cout << "ö���� ���������� �Է��ϼ���." << endl;
	cin >> math;

	int total = 0;

	total = Total(kor, eng, math);
	cout << "������" << Total(kor, eng, math) << "�Դϴ�." << endl;
	cout << "�����" << Average(total, 3.0f) << "�Դϴ�." << endl;
	cout << "�ְ�������" << HighScore(kor, eng, math) << "�Դϴ�." << endl;





	return 0;
}