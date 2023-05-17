#include "Util.h"
#include "Battle.h"
#include "Village.h"

// TODO 업데이트
// 상점, 인벤토리, 몬스터종류

int main()
{
	//Character* player[3] = { new Warrior(), new Mage(), new Crusader() };
	Warrior* warrior = new Warrior();
	Mage* mage = new Mage();
	Crusader* crusader = new Crusader();

	int selectButton = 1;
	while (selectButton != 0)
	{
		cout << "원하시는 행동을 선택하세요." << endl;
		cout << "1.마을  2.사냥터  0.떠나기" << endl;
		cin >> selectButton;

		switch (selectButton)
		{
		case 1:
			VillageMenu(warrior, mage, crusader);
			break;

		case 2:
		{
			Clear();
			cout << "던전에 입장중입니다..." << endl;
			Delay();
			Clear();
			Monster* monster = new Monster();
			//Battle(player[0], &player[1], &player[2], monster);
			Battle(warrior, mage, crusader, monster);
			delete monster;
			monster = nullptr;
			break;
		}

		case 0:
			cout << "종료되었습니다." << endl;
			break;

		default:
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}

	delete warrior;
	warrior = nullptr;
	delete mage;
	mage = nullptr;
	delete crusader;
	crusader = nullptr;

	return 0;
}