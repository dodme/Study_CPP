#include <iostream>
using namespace std;

// namespace?
/// > 이름공간

namespace Operator
{
	int Plus(int a, int b)
	{
		return a + b;
	}

	int Minus(int a, int b)
	{
		return a - b;
	}
}

namespace CharacterStat
{
	namespace Move
	{
		int moveSpeed = 0;
	}

	namespace Stat
	{
		int level = 0;
		int hp = 10;
		int mp = 10;
	}
}


int main()
{
	cout << Operator::Plus(CharacterStat::Stat::hp, CharacterStat::Stat::mp) << endl;

	return 0;
}