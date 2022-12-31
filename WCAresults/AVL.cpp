#include <iostream>
using namespace std;

class BTNode {
public:
    int data, height;
    BTNode* lChild;
    BTNode* rChild;
    BTNode() {
        lChild = NULL;
        rChild = NULL;
    }
};

class AVL {
public:

    BTNode* root;
    BTNode* Ploc;
    BTNode* loc;
    AVL() {
        root = NULL;
        Ploc = NULL;
        loc = NULL;
    };
    int Height(BTNode* node) {
        if (node == NULL) return 0;
        return node->height;
    }
    int Max(int a, int b) {
        return (a > b) ? a : b;
    }
    BTNode* rotateRight(BTNode* x) {
        BTNode* y = x->lChild;
        x->lChild = y->rChild;
        y->rChild = x;

        x->height = 1 + Max(Height(x->lChild), Height(x->rChild));
        y->height = 1 + Max(Height(y->lChild), Height(y->rChild));

        return y;
    }

    BTNode* rotateLeft(BTNode* x) {
        BTNode* y = x->rChild;
        x->rChild = y->lChild;
        y->lChild = x;

        x->height = 1 + Max(Height(x->lChild), Height(x->rChild));
        y->height = 1 + Max(Height(y->lChild), Height(y->rChild));


        return y;
    }
    BTNode* newNode(int val) {
        BTNode* node = new BTNode();
        node->data = val;
        node->height = 1;
        return node;
    }

    int getBalance(BTNode* Node) {
        if (Node == NULL) { return 0; }
        return Height(Node->lChild) - Height(Node->rChild);
    }

    BTNode* Insert(BTNode* node, int val) {
        if (node == NULL) {
            return(newNode(val));
        }
        if (val <= node->data) {
            node->lChild = Insert(node->lChild, val);
        }
        else {
            node->rChild = Insert(node->rChild, val);
        }

        node->height = 1 + max(Height(node->lChild), Height(node->rChild));

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
};
void preOrder(BTNode* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->lChild);
        preOrder(root->rChild);
    }
}

int main() {
    AVL t;
    t.root = NULL;

    t.root = t.Insert(t.root, 10);
    t.root = t.Insert(t.root, 20);
    t.root = t.Insert(t.root, 30);
    t.root = t.Insert(t.root, 40);
    t.root = t.Insert(t.root, 50);
    t.root = t.Insert(t.root, 25);

    preOrder(t.root);
    return 0;
}
