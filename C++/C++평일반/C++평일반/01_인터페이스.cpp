#include <iostream>
#include <combaseapi.h>
using namespace std;

// �������̽�
/// > ��������޼���θ� �̷���� Ŭ���� �񽺹����Ѱ�
/// > �ν��Ͻ�ȭ�� �Ұ��� : ��������޼����� ���Ǻΰ� �ҿ����ϱ⋚���� �޸� ������ �Ұ���
/// interface
/// combaseapi.h

interface ISample
{
	virtual void Method() abstract;
};

interface ISample2
{
	virtual void Method2() abstract;
};

// �θ�Ŭ�������� �߻�޼��尡 ���ǵ��� �ʾҴٸ� �ڽ��ʿ����� �ݵ�� �����ؾ��Ѵ�
class Sample : public ISample, ISample2
{
	// ISample��(��) ���� ��ӵ�
	virtual void Method() override
	{

	}

	// ISample2��(��) ���� ��ӵ�
	virtual void Method2() override
	{

	}
};

int main()
{
	// �ڵ� �ۼ��� ���������� ������ �Ұ���!
	//ISample s1;
	//ISample* s2 = new ISample();
	//s2->Method();
	//
	//delete s2;
	//s2 = nullptr;


	return 0;
}