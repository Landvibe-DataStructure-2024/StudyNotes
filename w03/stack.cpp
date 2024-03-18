// Created by 김수환 on 2024/03/14.
// 강의 자료
// w3p3

// cin.tie() 알려주기
// 클래스 구조체 차이 알려주기
// while(n--) 알려주기

#include <iostream>

using namespace std;


class Node {
private:
    int value;
    Node *next;
public:
    Node(int value);

    void setNext(Node *next);

    Node *getNext();

    int getValue();

    friend class LinkedList;
};


class LinkedList {
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList();

    bool empty();

    void increaseSize();

    void decreaseSize();

    int getSize();

    void addFront(int value);

    void removeFront();

    friend class Stack;
};

class Stack {
private:
    Node *top;
    LinkedList *stackList;
public:
    Stack();

    int getSize();

    bool empty();

    int getTop();

    void updateTop();

    void push(int x);

    int pop();
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string cmd;
    Stack *stack = new Stack();
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "size") {
            cout << stack->getSize() << "\n";
        } else if (cmd == "empty") {
            if (stack->empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (cmd == "top") {
            cout << stack->getTop() << "\n";
        } else if (cmd == "push") {
            int x;
            cin >> x;
            stack->push(x);
        } else if (cmd == "pop") {
            cout << stack->pop() << "\n";
        }
    }
}

Node::Node(int value) {
    this->value = value;
    next = nullptr;
}

int Node::getValue() {
    return value;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Node *Node::getNext() {
    return next;
}

LinkedList::LinkedList() {
    size = 0;
    head = tail = nullptr;
}

bool LinkedList::empty() {
    return (getSize() == 0);
}

void LinkedList::increaseSize() {
    size++;
}

void LinkedList::decreaseSize() {
    size--;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::addFront(int value) {
    Node *newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    increaseSize();
}

void LinkedList::removeFront() {
    if (empty()) {
        cout << "empty\n";
        return;
    }
    Node *delNode = head;
    head = delNode->next;
    delete delNode;
    decreaseSize();
}

Stack::Stack() {
    stackList = new LinkedList();
    top = stackList->head;
}

int Stack::getSize() {
    return stackList->getSize();
}

bool Stack::empty() {
    return getSize() == 0;
}

void Stack::updateTop() {
    top = stackList->head;
}

int Stack::getTop() {
    if (empty()) {
        return -1;
    }
    return top->getValue();
}

void Stack::push(int x) {
    stackList->addFront(x);
    updateTop();
}

int Stack::pop() {
    if (empty()) {
        return -1;
    }
    int poppedValue = getTop();
    stackList->removeFront();
    updateTop();
    return poppedValue;
}
