#include "01_Item.h"
#include "Character.h"

int main()
{
	// �⺻ ������ ���� ĳ���� ��ü ����
	Character* player = new Character("����ȣ~", 10, 10);
	player->PrintCharacterInfo();

	// �߰� ������ �ο��� ������ ��ü ����
	Item* item[3] = {new Item(), new Item(), new Item()};
	item[0]->SetItemInfo("�ռҵ�", 10, 0);
	item[1]->SetItemInfo("���", 25, 0);
	item[2]->SetItemInfo("õ����", 0, 10);

	// ��Ÿ~Ʈ
	while (1)
	{
		// ���ϴ� ������ ����
		int button = 0;
		cout << "���ϴ� �������� �����ϼ���." << endl;
		cout << "1. ";
		item[0]->PrintItemInfo();
		cout << endl;
		cout << "2. ";
		item[1]->PrintItemInfo();
		cout << endl;
		cout << "3. ";
		item[2]->PrintItemInfo();
		cout << endl;
		cout << "0. ����" << endl;

		// ������ ���� �� �ش� �����۸�ŭ �ɷ�ġ ����
		cin >> button;
		switch (button)
		{
		case 1:
			// ������ ���ݷ� getter ���� �÷��̾� �ɷ�ġ���ٰ� �����ָ� ���پ˾Ҵµ�
			// �������� �̺κи� ��������
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
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}


	// �޸� ����
	delete player;
	player = nullptr;

	for (int i = 0; i < 3; i++)
	{
		delete item[i];
		item[i] = nullptr;
	}


	return 0;
}