#include "Village.h"

void VillageMenu(Warrior* warrior, Mage* mage, Crusader* crusader)
{
	int villageMenu = 1;
	while (villageMenu != 0)
	{
		Clear();
		cout << "원하시는 메뉴를 선택하세요." << endl;
		cout << "1.플레이어정보  2.상점" << endl;
		cout << "3.여관    0.나가기" << endl;
		cin >> villageMenu;
		Clear();

		switch (villageMenu)
		{
		case 1:
#pragma region 플레이어정보
		{
			cout << "원하시는 메뉴를 선택하세요." << endl;
			cout << "1.캐릭터상태   2.인벤토리   0.나가기" << endl;
			int playerMenu = 0;
			cin >> playerMenu;
			Clear();

			switch (playerMenu)
			{
			case 1:
				cout << "원하시는 캐릭터를 선택해주세요." << endl;
				cout << "1.전사    2.마법사   3.성기사" << endl;
				cin >> playerMenu;
				Clear();

				switch (playerMenu)
				{
				case 1:
					while (playerMenu != 0)
					{
						warrior->PrintWarriorInfo();
						cout << "0.확인" << endl;
						cin >> playerMenu;
						Clear();
					}
					break;

				case 2:
					while (playerMenu != 0)
					{
						mage->PrintMageInfo();
						cout << "0.확인" << endl;
						cin >> playerMenu;
						Clear();
					}
					break;

				case 3:
					while (playerMenu != 0)
					{
						crusader->PrintCrusaderInfo();
						cout << "0.확인" << endl;
						cin >> playerMenu;
						Clear();
					}
					break;

				default:
					cout << "잘못된 입력입니다." << endl;
					break;
				}
#pragma endregion
				break;

			case 2:
				cout << "미구현입니다..." << endl;
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
			cout << "공사중입니다..." << endl;
			Delay();
			break;

		case 3:
			cout << "캐릭터의 체력이 완전히 회복되었습니다." << endl;

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
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}