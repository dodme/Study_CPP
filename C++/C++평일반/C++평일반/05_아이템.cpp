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
		cout << " �������� �����մϴ�." << endl;
		cout << "-------������ ����------" << endl;
		cout << "�̸� : " << itemName << endl;
		cout << "���� : " << itemTooltip << endl;
		cout << "ȿ�� : " << itemEffect << endl;
	}

	void UseItem()
	{
		cout <<  itemName << "�� ����մϴ�." << endl;
		cout << "���� : " << itemTooltip << endl;
		cout << "ȿ�� : " << itemEffect << endl;
		cout << "������ ��û��!" << endl;
		Delay();
	}

	void PrintItemInfo()
	{
		cout << "�̸� : " << itemName << endl;
		cout << "���� : " << itemTooltip << endl;
		cout << "ȿ�� : " << itemEffect << endl;
		Delay();
	}
};

int main()
{
	Item* items[] = {
		new Item("������", "�����", "�÷��̾ ������ �Ⱦ��մϴ�."),
		new Item("ȭ����", "�����", "�÷��̾ ������ �Ⱦ��մϴ�."),
		new Item("������", "�����", "�÷��̾ ������ �Ⱦ��մϴ�."),
		new Item("�����", "�����", "�÷��̾ ������ �Ⱦ��մϴ�."),
		new Item("�ݿ���", "�����", "�÷��̾ ���� �Ⱦ��մϴ�.")
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