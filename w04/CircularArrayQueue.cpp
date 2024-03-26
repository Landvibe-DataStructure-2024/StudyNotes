//
// Created by 김수환 on 2024/03/20.
//
// 2023-1-w4p3 문제
#include <iostream>

using namespace std;

class CircularArrayQueue {
private:
    int circularArr[20];
    int front;
    int rear;
    int size;
    int capacity;
public:
    CircularArrayQueue(int capacity);

    int getSize();

    bool empty();

    bool full();

    void printFront();

    void printRear();

    void enQueue(int data);

    void deQueue();
};

CircularArrayQueue::CircularArrayQueue(int capacity) {
    this->front = 0;
    this->rear = -1;
    this->size = 0;
    this->capacity = capacity;
}

int CircularArrayQueue::getSize() {
    return size;
}

bool CircularArrayQueue::empty() {
    return (size == 0);
}

bool CircularArrayQueue::full() {
    return (size == capacity);
}

void CircularArrayQueue::printFront() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << circularArr[front] << '\n';

}

void CircularArrayQueue::printRear() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << circularArr[rear] << '\n';

}

void CircularArrayQueue::enQueue(int data) {
    if (full()) {
        cout << "Full" << '\n';
        return;
    }
    rear = (rear + 1) % capacity;
    // 환형 배열 에서는 modulo 연산을 통해 rear를 지정합니다.

    circularArr[rear] = data;
    size++;
}

void CircularArrayQueue::deQueue() {
    if (empty()) {
        cout << "Empty" << '\n';
        return;
    }
    printFront();
    front = (front + 1) % capacity;
    // 환형 배열 에서는 modulo 연산을 통해 front를 지정합니다.

    size--;
}
