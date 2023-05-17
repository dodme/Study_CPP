#include "Village.h"

void VillageMenu(Warrior* warrior, Mage* mage, Crusader* crusader)
{
	int villageMenu = 1;
	while (villageMenu != 0)
	{
		Clear();
		cout << "���Ͻô� �޴��� �����ϼ���." << endl;
		cout << "1.�÷��̾�����  2.����" << endl;
		cout << "3.����    0.������" << endl;
		cin >> villageMenu;
		Clear();

		switch (villageMenu)
		{
		case 1:
#pragma region �÷��̾�����
		{
			cout << "���Ͻô� �޴��� �����ϼ���." << endl;
			cout << "1.ĳ���ͻ���   2.�κ��丮   0.������" << endl;
			int playerMenu = 0;
			cin >> playerMenu;
			Clear();

			switch (playerMenu)
			{
			case 1:
				cout << "���Ͻô� ĳ���͸� �������ּ���." << endl;
				cout << "1.����    2.������   3.�����" << endl;
				cin >> playerMenu;
				Clear();

				switch (playerMenu)
				{
				case 1:
					while (playerMenu != 0)
					{
						warrior->PrintWarriorInfo();
						cout << "0.Ȯ��" << endl;
						cin >> playerMenu;
						Clear();
					}
					break;

				case 2:
					while (playerMenu != 0)
					{
						mage->PrintMageInfo();
						cout << "0.Ȯ��" << endl;
						cin >> playerMenu;
						Clear();
					}
					break;

				case 3:
					while (playerMenu != 0)
					{
						crusader->PrintCrusaderInfo();
						cout << "0.Ȯ��" << endl;
						cin >> playerMenu;
						Clear();
					}
					break;

				default:
					cout << "�߸��� �Է��Դϴ�." << endl;
					break;
				}
#pragma endregion
				break;

			case 2:
				cout << "�̱����Դϴ�..." << endl;
				Delay();
				break;

			case 0:
				break;

			default:
				break;
			}
		}
		break;

		case 2:
			cout << "�������Դϴ�..." << endl;
			Delay();
			break;

		case 3:
			cout << "ĳ������ ü���� ������ ȸ���Ǿ����ϴ�." << endl;

			warrior->SetState(NormalAttack);
			mage->SetState(NormalAttack);
			crusader->SetState(NormalAttack);

			warrior->HealHp(warrior->GetHp());
			mage->HealHp(mage->GetHp());
			crusader->HealHp(crusader->GetHp());
			Delay();
			break;

		case 0:
			break;

		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}
}