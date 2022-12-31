#pragma once

#include <iostream>
#include "Utilities.h"

namespace my
{

template <class type>
class AVLtree {
private:
    struct Node {
        type data;
        int height;
        Node* lChild;
        Node* rChild;

        Node()
            :
            height(1),
            lChild(nullptr),
            rChild(nullptr)
        {}
    };

public:
    AVLtree()
        :
        root(nullptr)
    {}
    bool IsEmpty() const
    {
        return root == nullptr;
    }
    void Insert(const type& value)
    {
        root = Insert(root, value);
    }
    void printInOrder(const Node* start, int num = 0) const
    {
        if (start)
        {
            printInOrder(start->lChild, num + 1);

            std::cout << "|";
            for (int i = 0; i < num; i++) std::cout << " ";
            std::cout << start->data;
            for (int i = 0; i < num; i++) std::cout << " ";
            std::cout << "|";

            printInOrder(start->rChild, num + 1);
        }
    }
    const Node* begin() const
    {
        return root;
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
            Node* node = new Node();
            node->data = val;
            return node;
        }
        if (val <= node->data) {
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
private:
    Node* root;
};

}