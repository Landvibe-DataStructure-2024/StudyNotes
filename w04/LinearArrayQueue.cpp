//
// Created by 김수환 on 2024/03/20.
//
#include <iostream>

using namespace std;

class ArrayQueue {
private:
    int array[10000];
    int front;
    int rear;
    int size;
    int capacity;
public:
    ArrayQueue(int capacity);

    int getSize();

    bool empty();

    bool full();

    void printFront();

    void printRear();

    void enQueue(int data);

    void deQueue();
};

ArrayQueue::ArrayQueue(int capacity) {
    this->front = 0;
    this->rear = -1;
    this->size = 0;
    this->capacity = capacity;
}

int ArrayQueue::getSize() {
    return size;
}

bool ArrayQueue::empty() {
    return (size == 0);
}

bool ArrayQueue::full() {
    return (size == capacity);
}

void ArrayQueue::printFront() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << array[front] << '\n';
}

void ArrayQueue::printRear() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << array[rear] << '\n';
}

void ArrayQueue::enQueue(int data) {
    if (full()) {
        cout << "Full" << '\n';
        return;
    }
    rear++;
    array[rear] = data;
    size++;
}

void ArrayQueue::deQueue() {
    if (empty()) {
        cout << "Empty" << '\n';
        return;
    }
    printFront();
    front++;
    size--;
}
