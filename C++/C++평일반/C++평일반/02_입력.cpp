#include <iostream>
using namespace std;

int main()
{
	// ���ڿ��� �Է¹޽��ϴ�.
	char str[256];

	cout << "����� �����ϴ� ���α׷��־��� �����ΰ���~?" << endl;

	cin.getline(str, sizeof(str), '\n');
	// getline(���ڿ�, �Է¹��� ������ �ִ��, ���� ������ ����);
	cout << "�Է��� �� : " << str << endl;


	return 0;
}