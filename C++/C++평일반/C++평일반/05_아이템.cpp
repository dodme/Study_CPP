#include <iostream>
#include <Windows.h>
using namespace std;
#pragma warning (disable : 4996)

void Delay()
{
	system("cls");
	_sleep(3000);
}

class Item
{
private:
	char itemName[80];
	char itemTooltip[256];
	char itemEffect[80];
	
public:

	Item(const char* itemName, const char* itemTooltip, const char* itemEffect)
	{
		strcpy(this->itemName, itemName);
		strcpy(this->itemTooltip, itemTooltip);
		strcpy(this->itemEffect, itemEffect);
	}

	void DropItem()
	{
		cout << " 아이템을 습득합니다." << endl;
		cout << "-------아이템 정보------" << endl;
		cout << "이름 : " << itemName << endl;
		cout << "설명 : " << itemTooltip << endl;
		cout << "효과 : " << itemEffect << endl;
	}

	void UseItem()
	{
		cout <<  itemName << "을 사용합니다." << endl;
		cout << "설명 : " << itemTooltip << endl;
		cout << "효과 : " << itemEffect << endl;
		cout << "굉장히 엄청나!" << endl;
		Delay();
	}

	void PrintItemInfo()
	{
		cout << "이름 : " << itemName << endl;
		cout << "설명 : " << itemTooltip << endl;
		cout << "효과 : " << itemEffect << endl;
		Delay();
	}
};

int main()
{
	Item* items[] = {
		new Item("월요일", "디버프", "플레이어가 굉장히 싫어합니다."),
		new Item("화요일", "디버프", "플레이어가 굉장히 싫어합니다."),
		new Item("수요일", "디버프", "플레이어가 굉장히 싫어합니다."),
		new Item("목요일", "디버프", "플레이어가 굉장히 싫어합니다."),
		new Item("금요일", "디버프", "플레이어가 조금 싫어합니다.")
	};

	items[0]->DropItem();
	items[0]->UseItem();
	items[0]->PrintItemInfo();

	for (int i = 0; i < (sizeof(items) / sizeof(items[0])); i++)
	{
		delete items[i];
		items[i] = nullptr;
	}

	return 0;
}