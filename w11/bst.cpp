//
// Created by 김수환 on 2024/05/14.
//
#include<iostream>

using namespace std;

int arr[10001];
int n;


class Node {
public:
    Node *parent;
    Node *left;
    Node *right;
    int val;

    Node() { //dummy node
        this->val = 0;
        parent = left = right = nullptr;
    }

    Node(int val) {
        this->val = val;
        parent = left = right = new Node();
    }

    bool isDummy() {
        return val == 0;
    }
};


class BinarySearchTree {
public:
    Node *root;
    int size;
    int idx;

    BinarySearchTree() {
        root = new Node();
        size = 0;
    }


    Node *find(int val) {
        Node *curNode = root;
        while (curNode->val != val) {
            if (val < curNode->val) {
                if (curNode->left->isDummy()) {
                    return curNode;
                }
                curNode = curNode->left;
            } else {
                if (curNode->right->isDummy()) {
                    return curNode;
                }
                curNode = curNode->right;
            }
        }
        return curNode;
    }

    void insert(int val) {
        Node *newNode = new Node(val);
        if (size == 0) {
            root = newNode;
        } else {
            Node *parent = find(val);
            if (val < parent->val) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
            newNode->parent = parent;
        }
        size++;
    }

    void erase(int val) {
        Node *delNode = find(val);
        Node *parNode = delNode->parent;

        if (delNode->left->isDummy() && delNode->right->isDummy()) {// 자식이 0
            if (delNode == root) { // 지울 노드가 root인 경우
                this->root = new Node();
            } else {
                if (delNode == parNode->left) {
                    parNode->left = new Node();
                } else if (delNode == parNode->right) {
                    parNode->right = new Node();
                }
            }
        } else if (delNode->left->isDummy() || delNode->right->isDummy()) { // 자식이 1
            Node *child = (delNode->left->isDummy()) ? delNode->right : delNode->left;

            if (delNode == root) { // 지울 노드가 root인 경우
                this->root = child;
            } else {
                if (delNode == parNode->left) { // 지울 노드가 왼쪽 자식이면
                    parNode->left = child; // 부모 왼쪽에 child
                } else if (delNode == parNode->right) {
                    parNode->right = child; // 부모 오른쪽에 child
                }
            }
        } else { // 자식이 2
            Node *succ = delNode->right;
            Node *succPar = delNode;

            while (!succ->left->isDummy()) { // succ 찾기(오른쪽 subtree중 제일 왼쪽에 있는 노드)
                succPar = succ;
                succ = succ->left;
            }

            if (succ == succPar->left) { // succ이 왼쪽 자식이면
                succPar->left = succ->right; // 부모의 왼쪽 <- succ의 오른쪽
            } else {
                succPar->right = succ->right;  // 부모의 오른쪽 <- succ의 오른쪽
            }

            delNode->val = succ->val;
            delNode = succ;
        }
        size--;
        delete delNode;
    }


    int height(Node *node) {
        if (node->isDummy()) {
            return -1;
        }
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        return ((lHeight > rHeight) ? lHeight : rHeight) + 1;
    }

    int depth(Node *node) {
        if (node == root) {
            return 0;
        } else {
            return depth(node->parent) + 1;
        }
    }
};
