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
		cout << "²ÉÀÇ ÀÌ¸§ : " << name << endl;
		cout << name << "ÀÇ °¡°Ý : " << cost << "¿ø" << endl;
	}
};

class Rose : public Flower
{
public :
	Rose(const char* name, uint cost) : Flower(name, cost) {}

	//void SetFlowerInfo(uint cost) override
	//{
	//	strcpy(name, "Àå¹Ì");
	//	this->cost = cost;
	//}
};

class Tulip : public Flower
{
public:
	Tulip(const char* name, uint cost) : Flower(name, cost) {}

	//void SetFlowerInfo(uint cost) override
	//{
	//	strcpy(name, "Æ«¸³");
	//	this->cost = cost;
	//}
};

int main()
{
	Flower* flower[2] = { new Rose("Àå¹Ì", 100), new Tulip("Æ«¸³", 200) };

	for (int i = 0; i < sizeof(flower) / sizeof(flower[0]); i++)
	{
		flower[i]->PrintFlowerInfo();
		delete flower[i];
		flower[i] = nullptr;
	}

	//Flower* rose = new Rose("Àå¹Ì", 100);
	//Flower* tulip = new Tulip("Æ«¸³", 200);

	//rose->SetFlowerInfo(100);
	//rose->PrintFlowerInfo();

	//tulip->SetFlowerInfo(200);
	//tulip->PrintFlowerInfo();

	//delete rose;
	//rose = nullptr;


	return 0;
}