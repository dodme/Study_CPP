#include "Util.h"
#include "Battle.h"
#include "Village.h"

// TODO ������Ʈ
// ����, �κ��丮, ��������

int main()
{
	//Character* player[3] = { new Warrior(), new Mage(), new Crusader() };
	Warrior* warrior = new Warrior();
	Mage* mage = new Mage();
	Crusader* crusader = new Crusader();

	int selectButton = 1;
	while (selectButton != 0)
	{
		cout << "���Ͻô� �ൿ�� �����ϼ���." << endl;
		cout << "1.����  2.�����  0.������" << endl;
		cin >> selectButton;

		switch (selectButton)
		{
		case 1:
			VillageMenu(warrior, mage, crusader);
			break;

		case 2:
		{
			Clear();
			cout << "������ �������Դϴ�..." << endl;
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
			cout << "����Ǿ����ϴ�." << endl;
			break;

		default:
			cout << "�߸��� �����Դϴ�." << endl;
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