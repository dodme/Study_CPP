#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Node
{
public:
	T data;
	Node* back;
};

template<typename T>
class SingleLinkedList
{
public:
	Node<T>* Head = nullptr;
	Node<T>* Back = nullptr;

	~SingleLinkedList<T>()
	{
		delete Head;
		delete Back;
	}

	void CreateNode(T data)
	{
		Node<T>* temp = new Node<T>();
		temp->data = data;
		temp->back = Head;
		Head = temp;

		//delete temp;
	}

	void Print()
	{
		Back = Head;

		while (Back != nullptr)
		{
			cout << Back->data << endl;
			Back = Back->back;
		}
	}
};

int main()
{
	SingleLinkedList<string>* sll = new SingleLinkedList<string>();

	sll->CreateNode("±è¹ÎÀÚ");
	sll->CreateNode("±èÇÊµÎ");
	sll->CreateNode("¿ÀÇ³Å¹");
	sll->CreateNode("Ä«Ä¡ÇªÄ¡ÆÄ");

	sll->Print();

	delete sll;
	return 0;
}