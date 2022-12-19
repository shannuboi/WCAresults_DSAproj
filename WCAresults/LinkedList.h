#pragma once

template <typename datatype>
class LinkedList
{
private:
	struct Node
	{
		Node()
			:
			next(nullptr)
		{}
		datatype data;
		Node* next;
	};
public:
	class Iterator // Public interface for a Node
	{
	public:
		Iterator()
			:
			pNode(nullptr)
		{}
		Iterator(Node* in_pNode)
			:
			pNode(in_pNode)
		{}
		datatype& operator*()
		{
			return pNode->data;
		}
		Iterator& operator++()
		{
			pNode = pNode->next;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator nextIter(pNode->next);
			++(*this);
			return nextIter;
		}
		bool operator==(const Iterator& rhs)
		{
			return pNode == rhs.pNode;
		}
		bool operator!=(const Iterator& rhs)
		{
			return !(*this == rhs);
		}
	private:
		Node* pNode;
	};
public:
	LinkedList()
		:
		head(nullptr)
	{}
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
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator();
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
	Node* head;
};