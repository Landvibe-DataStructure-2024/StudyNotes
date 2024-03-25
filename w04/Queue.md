# 3. 큐 [Queue]

## 큐?
큐(queue)는 "대기줄"이라는 의미로, 먼저 집어 넣은 데이터가 먼저 나오는 구조로 저장하는 형식을 말한다.
![](https://velog.velcdn.com/images/genius00hwan/post/cf0cac30-200b-4e4d-a540-5564b31ecb67/image.png)

### 예시
- 오픈런을 기다리는 여러분
- 프린터의 출력 처리 순서
- 프로세스의 처리 순서

#### FIFO
First In First Out

### front
- 가장 먼저 추가한 데이터
- 가장 빨리 삭제될 데이터
- 맨 앞
### rear
- 가장 최근에 추가한 데이터
- 가장 나중에 삭제될 데이터
- 맨 뒤
## 연산

### enqueue
- queue에 데이터를 추가하는 연산
- 맨 뒤에 데이터를 추가한다.

### dequeue
- queue에서 데이터를 삭제하는 연산
- 맨 앞에 데이터를 삭제한다.

## 종류

### 선형 큐 (Linear queue)
![](https://velog.velcdn.com/images/genius00hwan/post/aaafac53-c5d6-44e4-93fa-690c3174da75/image.png)

- 크기가 제한되어 있다.
- 빈 공간을 사용하려면 모든 자료를 꺼내거나 자료를 한 칸씩 옮겨야 한다

### 환형 큐 (Circular queue) aka. 원형 큐
![](https://velog.velcdn.com/images/genius00hwan/post/0d35aa97-2857-4dfb-ac37-0728962c7b4a/image.png)

- 선형 큐의 문제점을 보완.
- front가 큐의 끝에 닿으면 큐의 맨 앞으로 자료를 보내어 원형으로 연결 하는 방식

## 구현
#### 노드
```cpp
public:
    Node *next = nullptr;
    Node *prev = nullptr;
    int data;

    Node(int data);
};

Node::Node(int data) {
    this->data = data;
    next = prev = nullptr;
}
```
### LinkedListQueue
- header는 항상 next로 가장 앞에 있는 데이터(front)를 가리키게 관리
- trailer는 항상 prev로 가장 뒤에 있는 데이터(rear)를 가리키게 관리
```cpp
class LinkedListQueue {
private:
    Node *header = nullptr;
    Node *trailer = nullptr;
    int size = 0;
public:
    LinkedListQueue();

    int getSize();

    bool empty();

    void printFront();

    void printRear();

    void enQueue(int data);

    void deQueue();

};
```
#### 생성자
```cpp
LinkedListQueue::LinkedListQueue() {
    size = 0;
    header = new Node(0);
    trailer = new Node(0);
    header->next = trailer;
    trailer->prev = header;
    header->prev = trailer->next = nullptr;
}
```
#### getSize() & empty()
```cpp
int LinkedListQueue::getSize() { 
	return size; 
}
```
```cpp
bool LinkedListQueue::empty() { 
	return (getSize() == 0); 
}
```
#### getFront()

```cpp
int LinkedListQueue::getFront() {
    if (empty()) return -1;
    return header->next->data;

}
```
#### gerRear()
```cpp
int LinkedListQueue::getRear() {
    if (empty()) return -1;
    return trailer->prev->data;

}
```
### enQueue()
- Doubly Linked List 구현 시 append() 연산과 동일합니다.
```cpp
void LinkedListQueue::enQueue(int data) {
    Node *newNode = new Node(data);
    newNode->prev = trailer->prev;
    newNode->next = trailer;

    trailer->prev->next = newNode;
    trailer->prev = newNode;
    size++;
}
```
### deQueue()
- Doubly Linked List 구현 시 removeFront() 연산과 동일합니다.
```cpp
void LinkedListQueue::deQueue() {
    if (empty()) return;
    printFront();
    Node *delNode = header->next;
    header->next = delNode->next;
    delNode->next->prev = header;

    delete delNode;
    size--;
}
```

**front, rear 변수가 아니라 header, trailer를 사용한 이유**

_(next, prev로 front, rear를 가리키게 한 이유)_

데이터가 0개 일때, 1개일 때 등 특이 상황에 예외처리 하기 싫어서


#### 전체 코드
https://github.com/Landvibe-DataStructure-2024/StudyNotes/blob/main/w04/LinkedListQueue.cpp

#### 배열로 구현한 선형 큐
https://github.com/Landvibe-DataStructure-2024/StudyNotes/blob/main/w04/ArrayQueue.cpp

#### 배열로 구현한 환형 큐
https://github.com/Landvibe-DataStructure-2024/StudyNotes/blob/main/w04/CircularArrayQueue.cpp