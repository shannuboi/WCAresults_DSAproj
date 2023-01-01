#pragma once

#include "Utilities.h"
#include <functional>

namespace my
{

template <class type, class Compare = std::less<type> >
class AVLtree {
private:
    struct Node {
        type data;
        int height;
        Node* lChild;
        Node* rChild;

        // Constructors

        Node()
            :
            height(1),
            lChild(nullptr),
            rChild(nullptr)
        {}
        Node(const type& val)
            :
            data(val),
            height(1),
            lChild(nullptr),
            rChild(nullptr)
        {}
        Node(const type & val, int height)
            :
            data(val),
            height(height),
            lChild(nullptr),
            rChild(nullptr)
        {}
    };
public:
    // Not true iterators (just a public interface for Node)
    class ConstIterator
    {
    public:
        ConstIterator()
            :
            pNode(nullptr)
        {}
        ConstIterator(Node* n)
            :
            pNode(n)
        {}
        const type& operator*() const
        {
            return pNode->data;
        }
        ConstIterator GetLeftChild() const
        {
            return ConstIterator(pNode->lChild);
        }
        ConstIterator& LeftChild()
        {
            pNode = pNode->lChild;
            return *this;
        }
        ConstIterator GetRightChild() const
        {
            return ConstIterator(pNode->rChild);
        }
        ConstIterator& RightChild()
        {
            pNode = pNode->rChild;
            return *this;
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
    class Iterator
    {
    public:
        Iterator()
            :
            pNode(nullptr)
        {}
        Iterator(Node* n)
            :
            pNode(n)
        {}
        type& operator*()
        {
            return pNode->data;
        }
        Iterator GetLeftChild() const
        {
            return Iterator(pNode->lChild);
        }
        Iterator& LeftChild()
        {
            pNode = pNode->lChild;
            return *this;
        }
        Iterator GetRightChild() const
        {
            return Iterator(pNode->rChild);
        }
        Iterator& RightChild()
        {
            pNode = pNode->rChild;
            return *this;
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
    // Constructor
    AVLtree()
        :
        root(nullptr)
    {}
    // Destructor
    ~AVLtree()
    {
        Destroy(root);
        root = nullptr;
    }
    // DeepCopy constructor
    AVLtree(const AVLtree& src)
    {
        *this = src;
    }
    // Move constructor
    AVLtree(AVLtree&& src)
    {
        *this = std::move(src);
    }
    // DeepCopy assignment
    AVLtree& operator=(const AVLtree& rhs)
    {
        Destroy(root);
        root = DeepCopy(rhs.root);
        return *this;
    }
    // Move assignment
    AVLtree& operator=(AVLtree&& rhs)
    {
        root = rhs.root;
        rhs.root = nullptr;
        return *this;
    }
    bool IsEmpty() const
    {
        return root == nullptr;
    }
    void Insert(const type& value)
    {
        root = Insert(root, value);
    }
    Iterator begin()
    {
        return Iterator(root);
    }
    ConstIterator begin() const
    {
        return ConstIterator(root);
    }
    Iterator end()
    {
        return Iterator();
    }
    ConstIterator end() const
    {
        return ConstIterator();
    }
private:
    int Height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return Height(node->lChild) - Height(node->rChild);
    }

    // returns replacement node after rotation
    Node* rotateRight(Node* oldroot) {
        Node* newroot = oldroot->lChild;
        oldroot->lChild = newroot->rChild;
        newroot->rChild = oldroot;

        oldroot->height = 1 + my::max(Height(oldroot->lChild), Height(oldroot->rChild));
        newroot->height = 1 + my::max(Height(newroot->lChild), Height(newroot->rChild));

        return newroot;
    }
    // returns replacement node after rotation
    Node* rotateLeft(Node* oldroot) {
        Node* newroot = oldroot->rChild;
        oldroot->rChild = newroot->lChild;
        newroot->lChild = oldroot;

        oldroot->height = 1 + my::max(Height(oldroot->lChild), Height(oldroot->rChild));
        newroot->height = 1 + my::max(Height(newroot->lChild), Height(newroot->rChild));

        return newroot;
    }

    // recursive insert function
    Node* Insert(Node* node, const type& val) {
        if (node == nullptr) {
            return (new Node(val));
        }
        if (comparer(val, node->data)) {
            node->lChild = Insert(node->lChild, val);
        }
        else {
            node->rChild = Insert(node->rChild, val);
        }        

        node->height = 1 + my::max(Height(node->lChild), Height(node->rChild));

        int balance = getBalance(node);

        // left rotation
        if (balance < -1 && (getBalance(node->rChild) == 0 || getBalance(node->rChild) == -1)) {
            return rotateLeft(node);
        }
        // right-left
        if (balance < -1 && getBalance(node->rChild) == 1) {
            node->rChild = rotateRight(node->rChild);
            return rotateLeft(node);
        }
        // right
        if (balance > 1 && (getBalance(node->lChild) == 0 || getBalance(node->lChild) == 1)) {
            return rotateRight(node);
        }
        //left-right
        if (balance > 1 && getBalance(node->lChild) == -1) {
            node->lChild = rotateLeft(node->lChild);
            return rotateRight(node);
        }

        return node;
    }
    // recursive function to destroy a tree
    void Destroy(Node* start)
    {
        if (start == nullptr) return;

        Destroy(start->lChild);
        Destroy(start->rChild);
        delete start;
    }
    // recursive function to copy a tree (returns root node of destination tree)
    Node* DeepCopy(const Node* src)
    {
        if (src == nullptr) return nullptr;

        Node* newnode = new Node(src->data, src->height);
        newnode->lChild = DeepCopy(src->lChild);
        newnode->rChild = DeepCopy(src->rChild);
        return newnode;
    }
private:
    Compare comparer;
    Node* root;
};

// Triverses in order and applies Unary predicate to each
// Unary func must have following prameters: func(type val)
// BTIterator must have LeftChild() and RightChild() member functions
template <typename BinaryTreeIterator, class UnaryFunc>
void InOrderTriversal(BinaryTreeIterator start, BinaryTreeIterator end, UnaryFunc func)
{
    if (start == end) return;

    InOrderTriversal(start.GetLeftChild(), end, func);
    func(*start);
    InOrderTriversal(start.GetRightChild(), end, func);
}

}