//
// Created by 김수환 on 2024/03/20.
//
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node *next = nullptr;
    Node *prev = nullptr;
    int data;

    Node(int data);
};

class LinkedListQueue {
private:
    Node *header = nullptr;
    Node *trailer = nullptr;
    int size = 0;
public:
    LinkedListQueue();

    int getSize();

    bool empty();

    int getFront();

    int getRear();

    void enQueue(int data);

    void deQueue();

};

Node::Node(int data) {
    this->data = data;
    next = prev = nullptr;
}

LinkedListQueue::LinkedListQueue() {
    size = 0;
    header = new Node(0);
    trailer = new Node(0);
    header->next = trailer;
    trailer->prev = header;
    header->prev = trailer->next = nullptr;
}

int LinkedListQueue::getSize() { return size; }

bool LinkedListQueue::empty() { return (getSize() == 0); }

int LinkedListQueue::getFront() {
    if (empty()) return -1;
    return header->next->data;

}

int LinkedListQueue::getRear() {
    if (empty()) return -1;
    return trailer->prev->data;

}

void LinkedListQueue::enQueue(int data) {
    Node *newNode = new Node(data);
    newNode->prev = trailer->prev;
    newNode->next = trailer;

    trailer->prev->next = newNode;
    trailer->prev = newNode;
    size++;
}

void LinkedListQueue::deQueue() {
    if (empty()) return;
    cout << getFront() << "\n";
    Node *delNode = header->next;
    header->next = delNode->next;
    delNode->next->prev = header;

    delete delNode;
    size--;
}