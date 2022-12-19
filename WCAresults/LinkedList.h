#pragma once

template <typename datatype>
class LinkedList
{
private:
	struct Node
	{
		datatype data;
		Node* next = nullptr;
	};
public:
	~LinkedList()
	{
		DestroyList(head);
	}
	void PushFront(datatype value)
	{
		Node* newnode = new Node;
		newnode->data = value;
		newnode->next = head;
		head = newnode;
	}
private:
	void DestroyList(Node* n)
	{
		if (n->next)
		{
			DestroyList(n->next);
		}
		delete n;
	}
private:
	Node* head = nullptr;
};