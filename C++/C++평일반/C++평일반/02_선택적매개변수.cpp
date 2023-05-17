#include <iostream>
using namespace std;

//void Sample(int value = 30)
//{
//	cout << value << endl;
//}

struct Stat
{
	int Level;
	int Hp;
	int Mp;
	int Exp;
};

void SetStat(Stat* stat, int hp, int mp, int exp, int level = 1)
{

}

int main()
{
	//Sample();
	//Sample(10);

	Stat stat;
	SetStat(&stat, 100, 100, 10);

	return 0;
}