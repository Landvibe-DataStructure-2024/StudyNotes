#include <iostream>

using namespace std;

class Node {
private:
    Node *prev;
    Node *next;
    int val;
public:
    Node(int val) {
        this->val = val;
        prev = next = nullptr;
    }

    friend class Iterator;

    friend class Sequence;
};

class Iterator {
private:
    Node *node;

public:
    void set(Node *node) {
        this->node = node;
    }

    Node *get() {
        return node;
    }

    Iterator *operator++() {
        node = node->next;
        return this;
    }

    Iterator *operator--() {
        node = node->prev;
        return this;
    }

    friend class Sequence;
};


class Sequence {
private:
    Node *header;
    Node *trailer;
    Iterator *iter;
    int size;

public:

    Sequence() {
        header = new Node(0);
        trailer = new Node(0);
        header->next = trailer;
        trailer->prev = header;
        trailer->next = nullptr;
        header->prev = nullptr;
        size = 0;

        iter = new Iterator();
        iter->set(header->next);
    }

    bool empty() {
        return size == 0;
    }

    void begin() {
        iter->set(header->next);
    }

    void end() {
        iter->set(trailer);
    }

    void insert(int val) {
        Node *newNode = new Node(val);
        iter->get()->prev->next = newNode;
        newNode->prev = iter->get()->prev;
        iter->get()->prev = newNode;
        newNode->next = iter->get();
        size++;
    }

    void erase() {
        if (empty()) {
            cout << "empty" << '\n';
            return;
        }
        if (iter->get() == trailer) {
            return;
        }
        Node *delNode = iter->get();
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;

        delete delNode;
        begin();
        size--;
    }

    void next() {
        if (iter->get() == trailer) {
            return;
        }
        iter++;
    }

    void prev() {
        if (iter->get() == header->next) {
            return;
        }
        iter--;
    }

    void find(int e) {
        if (size == 0) {
            cout << "Empty\n";
        } else {
            Node *curNode = header->next;
            int index = 0;

            while (curNode != trailer) {
                if (curNode->val == e) {
                    cout << index << "\n";
                    return;
                } else {
                    curNode = curNode->next;
                    index++;
                }
            }
            cout << "-1\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string cmd;
    cin >> n;
    Sequence *seq = new Sequence();
    while (n--) {
        cin >> cmd;
        if (cmd == "begin") {
            seq->begin();
        } else if (cmd == "end") {
            seq->end();
        } else if (cmd == "insert") {
            int e;
            cin >> e;
            seq->insert(e);
        } else if (cmd == "erase") {
            seq->erase();
        } else if (cmd == "++") {
            seq->next();
        } else if (cmd == "--") {
            seq->prev();
        } else if (cmd == "find") {
            int e;
            cin >> e;
            seq->find(e);
        }
    }
}
