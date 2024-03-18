# 2. Stack [스택]

## 스택이란?
스택(Stack)은 "쌓다"라는 의미로, 데이터를 차곡차곡 쌓아 올린 형태의 자료구조 입니다.
![](https://velog.velcdn.com/images/genius00hwan/post/c9bf2ae1-b268-4824-868b-e165ea812982/image.png)


#### LIFO
Last In First Out

### top
- 가장 최근에 추가된 데이터
- 가장 먼저 제거될 데이터
: 스택 맨 위에 있는 데이터
- 스택에서 유일하게 접근 가능한 데이터

### push
- 스택 맨 위에 데이터를 추가하는 연산
- top이 변경됨

### pop
- 스택 맨 위 데이터를 삭제하는 연산
- top이 변경됨

## 예시
- 뷔페에 있는 접시 탑
- ctrl + z
- 웹 브라우저 뒤로가기
- 함수 호출의 재귀적 구현
- _**후위 표기식**_

### 시간 복잡도
**getTop()** : O(1)
**push()** : O(1)
**pop()** : O(1)


## 구현
_(2023-week3-p3)_
### 노드와 단일 연결리스트
```cpp

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
```
### Stack
```cpp
class Stack {
private:
    Node *top; // 제일 위에 있는 애를 가리키는 포인터 변수
    LinkedList *stackList; // 단일 연결 리스트로 구현
public:
    Stack();

    int getSize();

    bool empty();

    int getTop();

    void updateTop();

    void push(int x);

    int pop();
};
```
#### 생성자
```cpp

Stack::Stack() {
    stackList = new LinkedList();
    top = stackList->head;
    // top은 단일연결리스트의 head
}
```
#### getSize()
```cpp

int Stack::getSize() {
    return stackList->getSize();
}

```
#### empty()
```cpp

bool Stack::empty() {
    return getSize() == 0;
}
```
#### updateTop()
```cpp

void Stack::updateTop() {
    top = stackList->head;
}
```
#### getTop()
```cpp

int Stack::getTop() {
    if (empty()) {
        return -1;
    }
    return top->getValue();
}
```
#### push()
```cpp

void Stack::push(int x) {
    stackList->addFront(x);
    updateTop();
}
```
#### pop()
```cpp

int Stack::pop() {
    if (empty()) {
        return -1;
    }
    int poppedValue = getTop();
    stackList->removeFront();
    updateTop();
    return poppedValue;
}
```
**단일 연결리스트를 제대로 작성했다면 어려울게 없습니다.**

>전체 코드
https://github.com/Landvibe-DataStructure-2024/StudyNotes/tree/main/w03

>### 연결리스트를 활용한 간단한 구현방법
https://github.com/Landvibe-DataStructure-2024/references/blob/master/2023-1%EC%BD%94%EB%93%9C/w03/w3p3.cpp
### 배열로 구현한 제일 간단한 구현방법
https://github.com/Landvibe-DataStructure-2024/references/blob/master/2023-1%EC%BD%94%EB%93%9C/w03/w3p1.cpp
