#include "01_Item.h"
#include "Character.h"

int main()
{
	// 기본 스텟을 가질 캐릭터 객체 생성
	Character* player = new Character("무야호~", 10, 10);
	player->PrintCharacterInfo();

	// 추가 스텟을 부여할 아이템 객체 생성
	Item* item[3] = {new Item(), new Item(), new Item()};
	item[0]->SetItemInfo("롱소드", 10, 0);
	item[1]->SetItemInfo("곡괭이", 25, 0);
	item[2]->SetItemInfo("천갑옷", 0, 10);

	// 스타~트
	while (1)
	{
		// 원하는 아이템 선택
		int button = 0;
		cout << "원하는 아이템을 선택하세요." << endl;
		cout << "1. ";
		item[0]->PrintItemInfo();
		cout << endl;
		cout << "2. ";
		item[1]->PrintItemInfo();
		cout << endl;
		cout << "3. ";
		item[2]->PrintItemInfo();
		cout << endl;
		cout << "0. 종료" << endl;

		// 아이템 선택 및 해당 아이템만큼 능력치 증가
		cin >> button;
		switch (button)
		{
		case 1:
			// 아이템 공격력 getter 만들어서 플레이어 능력치에다가 더해주면 될줄알았는데
			// 오류나서 이부분만 막혔어요ㅠ
			player->AddDamage(item[0]->GetDamage);
			player->PrintCharacterInfo();
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			player->PrintCharacterInfo();
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}


	// 메모리 해제
	delete player;
	player = nullptr;

	for (int i = 0; i < 3; i++)
	{
		delete item[i];
		item[i] = nullptr;
	}


	return 0;
}