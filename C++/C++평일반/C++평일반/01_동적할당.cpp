#include <iostream>
using namespace std;

// �����Ҵ� < - > �����Ҵ�

// ���� �޸� �Ҵ� Ű���� : new
// ���� �޸� ���� Ű���� : delete

// �޸𸮿���(RAM) 4�ܰ�
//----------------------
// Code Area(�ڵ念��)		: �ü���� �����ϴ� �޸�
// Data Area(�����Ϳ���)		: �����ڰ� ���Ƿ� �����Ҽ� ����.
/// << MessageQueue(�Լ�ȣ��޸�)
// Stack Area(���ÿ���)		: �����޸�
/// << static
/// << ���� �޸��� �ִ������ �ʰ������� Stakc Overflow�� �߻��Ѵ�.
// Heap Area(������)			: �����޸�
/// << new

int main()
{
	int* p = new int;
	delete p;
	p = nullptr;


	return 0;
}