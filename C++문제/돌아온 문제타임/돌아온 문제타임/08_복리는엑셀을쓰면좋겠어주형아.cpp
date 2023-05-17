#include <iostream>
using namespace std;

int InvestA(int money, int year, int plusYear)
{
	if (year >= plusYear)
	{
		money = money + money * 0.05f;
		plusYear++;
		InvestA(money, year, plusYear);
	}

	return money;
}

int InvestB(int money, int year, int plusYear)
{
	if (year >= plusYear)
	{
		money = money + money * 0.2f;
		plusYear += 3;
		InvestB(money, year, plusYear);
	}

	return money;
}

int InvestC(int money, int year, int plusYear)
{
	if (year >= plusYear)
	{
		money = money + money * 0.35f;
		plusYear += 5;
		InvestC(money, year, plusYear);
	}

	return money;
}

int main()
{
	int money = 0, year = 0;
	int maxMoney = 0;
	int interestA = 0, interestB = 0, interestC = 0;

	cin >> money;
	cin >> year;

	interestA = InvestA(money, year, 1);
	interestB = InvestB(money, year, 3);
	interestC = InvestC(money, year, 5);

	cout << interestA << endl;
	cout << interestB << endl;
	cout << interestC << endl;

	//maxMoney = max(interestA, interestB);
	//maxMoney = max(maxMoney, interestC);

	//if (maxMoney == interestA)
	//	cout << "가장 이익인 투자는 A투자입니다." << endl;
	//else if (maxMoney == interestB)
	//	cout << "가장 이익인 투자는 B투자입니다." << endl;
	//else
	//	cout << "가장 이익인 투자는 C투자입니다." << endl;

	//cout << "최고 이자는 " << maxMoney - money << "입니다." << endl;

	return 0;
}