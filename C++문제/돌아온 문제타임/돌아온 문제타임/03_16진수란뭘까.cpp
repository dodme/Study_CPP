#include <iostream>>
using namespace std;

int main()
{
	int num = 0;

	cout << "16���� A ~ F������ ���� �Է��ϼ���." << endl;
	cin >> hex >> num;

	if (num > 16 || num < 10)
	{
		cout << "�߸��� ���Դϴ�." << endl;
		return 0;
	}

	for (int i = 1; i < 16; i++)
	{
		cout << hex << num << " X " << i << " = " << num * i << endl;
	}

	
	return 0;
}