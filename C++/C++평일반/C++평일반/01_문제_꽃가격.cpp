#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

typedef unsigned int uint;

class Flower
{
protected :
	char name[80];
	uint cost;

public :
	Flower(const char* name, uint cost)
	{
		strcpy(this->name, name);
		cost = cost;
	}

	//virtual void SetFlowerInfo(uint cost)
	//{
	//	this->cost = cost;
	//}

	void PrintFlowerInfo()
	{
		cout << "���� �̸� : " << name << endl;
		cout << name << "�� ���� : " << cost << "��" << endl;
	}
};

class Rose : public Flower
{
public :
	Rose(const char* name, uint cost) : Flower(name, cost) {}

	//void SetFlowerInfo(uint cost) override
	//{
	//	strcpy(name, "���");
	//	this->cost = cost;
	//}
};

class Tulip : public Flower
{
public:
	Tulip(const char* name, uint cost) : Flower(name, cost) {}

	//void SetFlowerInfo(uint cost) override
	//{
	//	strcpy(name, "ƫ��");
	//	this->cost = cost;
	//}
};

int main()
{
	Flower* flower[2] = { new Rose("���", 100), new Tulip("ƫ��", 200) };

	for (int i = 0; i < sizeof(flower) / sizeof(flower[0]); i++)
	{
		flower[i]->PrintFlowerInfo();
		delete flower[i];
		flower[i] = nullptr;
	}

	//Flower* rose = new Rose("���", 100);
	//Flower* tulip = new Tulip("ƫ��", 200);

	//rose->SetFlowerInfo(100);
	//rose->PrintFlowerInfo();

	//tulip->SetFlowerInfo(200);
	//tulip->PrintFlowerInfo();

	//delete rose;
	//rose = nullptr;


	return 0;
}