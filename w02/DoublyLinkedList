# 1. 2 Doubly Linked List [이중 연결 리스트]

![](https://velog.velcdn.com/images/genius00hwan/post/f5efa0f8-7fd3-4855-902a-03fe29f186dd/image.png)
## 이중 연결 리스트
단일 연결 리스트의 단점인 단방향 흐름을 **2개의 링크 필드**를 이용하여 **양방향**으로 움직일 수 있게 만든 것

### 노드
세가지 필드로 구성되어 있다.
- value : 노드가 갖고 있는 값
- next : 다음 노드의 주소를 가리키는 포인터 
- **prev** : 이전 노드의 주소를 가리키는 포인터

### 구성

#### 노드
- 값
- 다음 노드에 대한 포인터
- 이전 노드에 대한 포인터
#### Header
- 처음 노드를 가리키는 노드
- 의미있는 값을 가지고 있지 않음
- "시작" 이라는 의미
#### Trailer
- 마지막 노드를 가리키는 노드
- 의미있는 값을 가지고 있지 않음
- "마지막" 이라는 의미
### 기능
- 생성 : insert, append
- 탐색 : print, printReserve
- 수정 : update
- 삭제 : delete

## 구현

### 노드
```cpp
class node {
private:
    node *next;
    node *prev;
    int value;

    node(int value);

    friend class DoublyLinkedList;
};

node::node(int value) {
    this->value = value;
    next = prev = nullptr;
}
```
### Doubly Linked List
```cpp

class DoublyLinkedList {
private:
    int listSize;
    node *header;
    node *trailer;
public:
    DoublyLinkedList();

    bool empty();

    int getSize();

    void setSize(int size);

    void print();

    void printReserve();

    void append(int value);

    void insert(int idx, int value);

    int erase(int idx);

    void update(int oldValue, int newValue);


};
```
empty() 
```cpp
bool DoublyLinkedList::empty() { 
	return (getSize() == 0); 
}
```
getSize()
```cpp
int DoublyLinkedList::getSize() {
	return listSize;
}
```
setSize()
```cpp
void DoublyLinkedList::setSize(int size) { 
	this->listSize = size; 
}

```
#### append : 맨뒤에 추가하기
맨뒤에 노드를 나타내는 trailer 바로 앞에다가 노드를 추가
- trailer 앞 노드의 next를 새로운 노드로
- 새로운 노드의 prev를 trailer의 앞노드로(기존의 맨 뒤에 있는 노드)
- trailer의 prev를 새로운 노드로
- 새로운 노드의 next는 trailer

```cpp
void DoublyLinkedList::append(int value) {
    node *newNode = new node(value);

    newNode->next = trailer;
    newNode->prev = trailer->prev;
	trailer->prev->next = newNode;
    trailer->prev = newNode;

    setSize(getSize() + 1);
    print();
}
```
#### insert : 추가하고 싶은 위치를 찾아 삽입

맨앞에 추가하고 싶은 경우
- header 다음노드의 prev를 새로운 노드로
- 새로운 노드의 next를 header의 next(기존 맨앞에 있던 노드)로
- header 의 next를 새로운 노드로
- 새로운 노드의 prev를 헤더로

맨뒤에 추가하고 싶은 경우
- append()

중간에 추가하고 싶은 경우
- for문을 활용해 추가하고 싶은 위치 찾기 
curNode : 기준점이 될 노드, 추가하고 싶은 위치 바로 전
- 새로운 노드의 prev를 curNode로
- 새로운 노드의 next를 curNode의 다음 노드로
- curNode 다음노드의 prev를 새로운 노드로
- curNode의 next를 새로운 노드로
```cpp
void DoublyLinkedList::insert(int idx, int value) {
    if (idx < 0 || idx > getSize()) {
        return;
    }
    if (idx == 0) {
        node *newNode = new node(value);

        newNode->next = header->next;
        newNode->prev = header;
        header->next->prev = newNode;
        header->next = newNode;
        setSize(getSize() + 1);


    } else if (idx == getSize()) {
        append(value);
    } else {
        node *newNode = new node(value);

        node *curNode = header->next;
        for (int i = 0; i < idx - 1; i++) {
            curNode = curNode->next;
        }
        newNode->prev = curNode;
        newNode->next = curNode->next;
        curNode->next->prev = newNode;
        curNode->next = newNode;
        setSize(getSize() + 1);
    }

}
```
#### delete : 위치를 찾아 해당 노드를 삭제
- for문을 활용해 위치 찾기
- 지울 노드 이전 노드의 next를 지울 노드의 next로
- 지울 노드 다음 노드의 prev를 지울 노드의 prev로
- 메모리에서 지울 노드를 해제 (delete)
- size 수정
```cpp

int DoublyLinkedList::erase(int idx) {
    if (empty() || idx >= getSize()) {
        return -1;
    } else {
        node *delNode = header->next;
        for (int i = 0; i < idx; i++) {
            delNode = delNode->next;
        }
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        int delVal = delNode->value;
        delete delNode;
        setSize(getSize() - 1);
        return delVal;
    }
}
```
#### update : 원하는 값을 찾아서 수정
- find라는 flag 변수 활용
- 기존 노드를 탐색 하면서 원하는 값을 찾아 새로운 값으로 변경
- 원하는 값을 찾아서 변경하면 find 라는 변수를 true로 변경
- find 값이 true 이면 print
- 찾은 적 없으면 "Not found" 출력

```cpp
void DoublyLinkedList::update(int oldValue, int newValue) {
    if (empty()) {
        cout << "empty" << endl;
        return;
    } else {
        node *curNode = header->next;
        bool find = false;
        while (curNode->next != nullptr) {
            if (curNode->value == oldValue) {
                curNode->value = newValue;
                find = true;
            }
            curNode = curNode->next;
        }
        if (find) {
            print();
        } else {
            cout << "Not found" << endl;
        }
    }
}
```
#### print : 탐색
앞에서 부터 하나씩 값을 출력
- header 다음 노드 부터 tailer 전 노드 까지

```cpp
void DoublyLinkedList::print() {
    if (empty()) {
        cout << "empty" << endl;
        return;
    } else {
        node *curNode = header->next;
        while (curNode->next != nullptr) {
            cout << curNode->value << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }
}
```
#### printReserve : 탐색
뒤에서 부터 하나씩 값을 출력
- traile 이전 노드 부터 header 다음 노드 까지
```cpp
void DoublyLinkedList::printReserve() {
    if (empty()) {
        cout << "empty" << endl;
        return;
    } else {
        node *curNode = trailer->prev;
        while (curNode->prev != nullptr) {
            cout << curNode->value << " ";
            curNode = curNode->prev;
        }
        cout << endl;
    }
}
```
