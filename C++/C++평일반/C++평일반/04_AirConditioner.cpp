#include <iostream>
using namespace std;

// Airconditional 클래스를 정의합니다.
// -----기능----
// 온도 1도증가, 온도 1도감소, 현재온도, 전원 OnOff

class Airconditional
{
private:
	int temp = 18;

public:
	Airconditional()
	{
		cout << "전원을 켭니다." << endl;
		PrintTemp();
	}

	~Airconditional()
	{
		cout << "전원을 끕니다." << endl;
	}

	void PrintTemp()
	{
		cout << "현재온도 : " << temp << endl;
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
		cout << "원하는 기능을 선택하세요." << endl;
		cout << "1.온도올림 2.온도내림 0.종료" << endl;

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
			cout << "잘못된 입력입니다." << endl;
			break;
		}

	}


	return 0;
}

// 숙제
/// Item 클래스를 정의합니다.
// --- 기능 ---
/// 아이템의 이름, 설명, 효과
/// 아이템 슴득, 아이템 사용, 아이템 설명출력