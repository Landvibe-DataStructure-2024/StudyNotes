//
// Created by 김수환 on 2024/04/08.
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

    Node(int val, int depth) {
        parent = nullptr;
        this->val = val;
        this->depth = depth;
    }
};

class Tree {
public:
    Node *root;
    vector<Node *> nodeList;

    Tree() {
        root = new Node(1, 0);
        nodeList.emplace_back(root);
    }

    void insert(int x, int y) {
        Node *parentNode = findNode(x);
        if (parentNode == nullptr || findNode(y) != nullptr) {
            cout << -1 << '\n';
            return;
        }
        Node *newNode = new Node(parentNode, y);
        parentNode->childList.emplace_back(newNode);
        nodeList.push_back(newNode);
    }

    void erase(int x) {
        Node *delNode = findNode(x);
        if (delNode == nullptr) {
            cout << -1 << '\n';
            return;
        }
        for (auto node: delNode->childList) {
            delNode->parent->childList.emplace_back(node);
            node->parent = delNode->parent;
        }
        for (int i = 0; i < delNode->parent->childList.size(); i++) {
            if (delNode->parent->childList[i] == delNode) {
                delNode->parent->childList.erase(delNode->parent->childList.begin() + i);
                break;
            }
        }
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i] == delNode) {
                nodeList.erase(nodeList.begin() + i);
                break;
            }
        }

    }

    void parent(int x) {
        Node *targetNode = findNode(x);
        if (targetNode == nullptr) {
            cout << -1 << '\n';
            return;
        }
        cout << targetNode->parent->val << '\n';

    }

    void child(int x) {
        Node *targetNode = findNode(x);
        if (targetNode == nullptr || targetNode->childList.empty()) {
            cout << -1 << '\n';
            return;
        }
        for (auto node: targetNode->childList) {
            cout << node->val << ' ';
        }
        cout << '\n';

    }

    Node *findNode(int x) {
        for (auto node: nodeList) {
            if (node->val == x) {
                return node;
            }
        }
        return nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string cmd;
    cin >> t;
    Tree *tree = new Tree();
    while (t--) {
        cin >> cmd;
        int arg1, arg2;
        if (cmd == "insert") {
            cin >> arg1 >> arg2;
            tree->insert(arg1, arg2);
        } else if (cmd == "delete") {
            cin >> arg1;
            tree->erase(arg1);
        } else if (cmd == "parent") {
            cin >> arg1;
            tree->parent(arg1);
        } else if (cmd == "child") {
            cin >> arg1;
            tree->child(arg1);
        }

    }
}
