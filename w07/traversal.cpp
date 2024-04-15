//
// Created by 김수환 on 2024/04/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node *parent;
    vector<Node *> childList;
    int val;
    int depth;

    Node(Node *p, int val) {
        this->parent = p;
        this->val = val;
        this->depth = parent->depth + 1;
    }

    Node() {
        parent = nullptr;
        val = 1;
        depth = 0;
    }
};

class Tree {
public:
    Node *root;
    vector<Node *> nodeList;

    Tree() {
        root = new Node();
        nodeList.push_back(root);
    }

    void insert(int par, int child) {
        int parIdx = findIdx(par);
        if (parIdx == -1 || findIdx(child) != -1) {
            cout << -1 << '\n';
            return;
        }
        Node *parNode = nodeList[parIdx];
        Node *newNode = new Node(parNode, child);
        parNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
    }

    int findIdx(int val) {
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i]->val == val) {
                return i;
            }
        }
        return -1;
    }

    void preOrderTraversal(Node *node) {
        cout << node->val << ' ';
        for (Node *child: node->childList) {
            preOrderTraversal(child);
        }
    }

    void postOrderTraversal(Node *node) {
        for (Node *child: node->childList) {
            postOrderTraversal(child);
        }
        cout << node->val << ' ';
    }

    void inOrderTraversal(Node *node) {
        int flag = node->childList.size() / 2;
        for (int i = 0; i < flag; i++) {
            inOrderTraversal(node->childList[i]);
        }
        cout << node->val << ' ';
        for (int i = flag; i < node->childList.size(); i++) {
            inOrderTraversal(node->childList[i]);
        }
    }
};
