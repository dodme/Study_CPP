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
	//	cout << "���� ������ ���ڴ� A�����Դϴ�." << endl;
	//else if (maxMoney == interestB)
	//	cout << "���� ������ ���ڴ� B�����Դϴ�." << endl;
	//else
	//	cout << "���� ������ ���ڴ� C�����Դϴ�." << endl;

	//cout << "�ְ� ���ڴ� " << maxMoney - money << "�Դϴ�." << endl;

	return 0;
}