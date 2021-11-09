#include <iostream>
using namespace std;

struct Node
{
	int item;
	Node* next;
	Node(int i)
	{
		item = i;
		next = nullptr;
	}

	Node()
	{
		item = 0;
		next = nullptr;
	}
};

class LinkList
{
	Node* item;
	int size = 0;

public:
	LinkList()
	{
		item = new Node();
		size = 1;
	}
	LinkList(int val)
	{
		item = new Node(val);
		size = 0;
	}

	int getSize()
	{
		return size;
	}
	
	int getFirst()
	{
		if (size == 0)
		{
			return false;
		}
		return item->item;
	}

	Node* getNode(int pos)
	{
		if (pos < 1 || pos > size)	
		{
			return nullptr;
		}
		Node* p = item;
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
		}
		return p;
	}

	Node* getLastNode()
	{
		return getNode(size);
	}

	int get(int pos)
	{
		Node* node = getNode(pos);
		if (node != nullptr)
		{
			return node->item;
		}
		return 0;
	}

	void insert(int item, int pos)
	{
		if (pos < 0 || pos > size)
		{
			return;
		}
		if (pos == 0)
		{
			addFirst(item);
			return;
		}
		Node* node = new Node(item);
		Node* p = this->item;
		for (int i = 1; i < pos; i++)
		{
			p = p->next;
		}
		node->next = p->next;
		p->next = node;
		size += 1;
	}
	
	void addFirst(int item)
	{
		Node* node = new Node(item);
		node->next = this->item;
		this->item = node;
		size += 1;
	}

	void addLast(int item)
	{
		insert(item, size);
	}

	bool set(int item, int pos)
	{
		Node* node = getNode(pos);
		if (node)
		{
			node->item = item;
			return true;
		}
		return false;
	}
};

int main()
{
	LinkList* L = new LinkList();
	L->addFirst(1);
	L->addLast(2);
	cout << L->getSize() << endl;
	cout << L->get(1) << endl;
	cout << L->get(2) << endl;
	cout << L->get(3) << endl;
	L->set(2, 2);
	L->set(3, 3);
	cout << L->get(2) << endl;
	cout << L->get(3) << endl;
}
