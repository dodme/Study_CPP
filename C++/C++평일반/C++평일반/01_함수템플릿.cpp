#include <iostream>
using namespace std;

// �Ϲ�ȭ
/// > Ư���� �������κ��� ����� �������� ���°�

// �Ϲ�ȭ ���α׷���
/// > Ư���� �ڷ������κ��� ����� �ڷ������� ���°�
/// > template<typename T> / template<class T>

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

int main()
{
	Print<int>(10);
	Print<float>(100.1f);
	Print<char>('A');


	return 0;
}