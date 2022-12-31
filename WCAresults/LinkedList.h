#pragma once

namespace my
{

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
	class ConstIterator // Public interface for a Node
	{
	public:
		ConstIterator()
			:
			pNode(nullptr)
		{}
		ConstIterator(Node* in_pNode)
			:
			pNode(in_pNode)
		{}
		const datatype& operator*()
		{
			return pNode->data;
		}
		ConstIterator& operator++()
		{
			pNode = pNode->next;
			return *this;
		}
		ConstIterator operator++(int)
		{
			Iterator nextIter(pNode->next);
			++(*this);
			return nextIter;
		}
		bool operator==(const ConstIterator& rhs)
		{
			return pNode == rhs.pNode;
		}
		bool operator!=(const ConstIterator& rhs)
		{
			return !(*this == rhs);
		}
	private:
		Node* pNode;
	};
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
		operator ConstIterator()
		{
			return ConstIterator(pNode);
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
	// Deep copy. (very slow since linkedlist does not have a end/last node ptr)
	LinkedList(const LinkedList<datatype>& source)
		:
		head(nullptr)
	{
		*this = source;
	}
	// Deep move
	LinkedList(LinkedList<datatype>&& source)
	{
		head = source.head;
		source.head = nullptr;
	}
	// Deep copy. (very slow since linkedlist does not have a end/last node ptr)
	LinkedList& operator=(const LinkedList<datatype>& rhs)
	{
		DestroyList(head);

		for (auto iter = rhs.begin(); iter != rhs.end(); iter++)
		{
			PushBack(*iter);
		}

		return *this;
	}
	LinkedList& operator=(LinkedList<datatype>&& rhs)
	{
		head = rhs.head;
		rhs.head = nullptr;
	}
	void PushFront(const datatype& value)
	{
		Node* newnode = new Node;
		newnode->data = value;
		newnode->next = head;
		head = newnode;
	}
	void PushBack(const datatype& value)
	{
		Node* newnode = new Node;
		newnode->data = value;
		newnode->next = nullptr;
		if (!head)
		{
			head = newnode;
		}
		else
		{
			Node* cur = head;
			while (cur->next) cur = cur->next;
			cur->next = newnode;
		}
	}

	// returns iterator holding head node
	Iterator begin()
	{
		return Iterator(head);
	}
	// returns iterator holding to node after last (i.e. in this case nullptr)
	Iterator end()
	{
		return Iterator();
	}
	// returns const iterator holding head node
	ConstIterator begin() const
	{
		return ConstIterator(head);
	}
	// returns const iterator holding to node after last (i.e. in this case nullptr)
	ConstIterator end() const
	{
		return Iterator();
	}
private:
	void DestroyList(Node* n)
	{
		if (!n) return;
		if (n->next)
		{
			DestroyList(n->next);
		}
		delete n;
	}
private:
	Node* head;
};

}