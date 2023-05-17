#include <iostream>
using namespace std;

// Airconditional Ŭ������ �����մϴ�.
// -----���----
// �µ� 1������, �µ� 1������, ����µ�, ���� OnOff

class Airconditional
{
private:
	int temp = 18;

public:
	Airconditional()
	{
		cout << "������ �մϴ�." << endl;
		PrintTemp();
	}

	~Airconditional()
	{
		cout << "������ ���ϴ�." << endl;
	}

	void PrintTemp()
	{
		cout << "����µ� : " << temp << endl;
	}

	void TempUp()
	{
		temp++;
		PrintTemp();
	}

	void TempDown()
	{
		temp--;
		PrintTemp();
	}
};


int main()
{
	Airconditional* aircon = new Airconditional();
	while (1)
	{
		cout << "���ϴ� ����� �����ϼ���." << endl;
		cout << "1.�µ��ø� 2.�µ����� 0.����" << endl;

		int button = 0;
		cin >> button;

		switch (button)
		{
		case 1:
			aircon->TempUp();
			break;
		case 2:
			aircon->TempDown();
			break;
		case 0:
			delete aircon;
			aircon = nullptr;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}

	}


	return 0;
}

// ����
/// Item Ŭ������ �����մϴ�.
// --- ��� ---
/// �������� �̸�, ����, ȿ��
/// ������ ����, ������ ���, ������ �������