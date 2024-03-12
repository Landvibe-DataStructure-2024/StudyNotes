# 1. 1 Singly Linked List [단일 연결 리스트]

![](https://velog.velcdn.com/images/genius00hwan/post/6829bd72-dbb1-4541-a02e-125075de6dfe/image.png)
## 연결 리스트
여러 데이터를 사용하는 경우

- 배열 100칸 선언, 10개만 사용 : 메모리 낭비
- 배열 100칸 선언, 101개 사용 : 메모리 부족

데이터를 필요한 만큼 사용하는 자료구조, 데이터가 순차적으로 이어져 있는 선형 구조

### 노드
두가지의 필드로 구성되어 있다.
- value : 노드가 갖고 있는 값
- next : 다음 노드의 주소를 가리키는 포인터
### 구성

#### 노드
- 값
- 포인터 : 다음 노드에 대한 포인터
#### Head
- ~~대가리~~
- 가장 앞에 있는 노드
#### Tail
- 가장 뒤에 있는 노드

![](https://velog.velcdn.com/images/genius00hwan/post/81554efa-47d3-4fed-93ac-f965c60b8ffe/image.png)

### 장/단점
👍 
- 구현이 쉽고, 추가, 삽입, 삭제가 쉽다.
- 포인터 정보를 활용해 다음 노드를 쉽게 가져올 수 있다.

👎 
- 메모리가 추가로 필요하다. (포인터 정보)
- 탐색이 오래 걸린다.

### 기능
- 추가 : append, insert
- 탐색 : getMin, print
- 삭제 : erase

## 구현
### 노드
```cpp
class node {
private:
    int val;
    node *next;

public:
    node(int val) {
        this->val = val;
        next = nullptr;
    }

    void setNext(node *nextNode) {
        this->next = nextNode;
    }

    node *getNext() {
        return next;
    }

    int getVal() {
        return val;
    }

};
```

### 연결 리스트
```cpp
class linkedList {
public:
    linkedList();

    bool empty();

    void append(int val);

    void insert(int idx, int val);

    int erase(int idx);

    void print();

    void updateSize(int n);

    void getMin();

private:
    node *head;
    node *tail;
    int size;
};

```
#### 생성자 
```cpp
linkedList() { // 기본 생성자, 초기화
    head = nullptr;
    tail = nullptr;
    size = 0;
}
```

#### updateSize()
```cpp
updateSize(int n) {
    size += n;
}
```
#### empty()

```cpp
bool linkedList::empty() {
    if (size == 0) {
        return true;
    }
    return false;
}

```

#### append() : 추가
맨뒤에 추가하기
- 비어있는 경우
새로운 노드가 head이자 tail
- 나머지 경우
    - 기존 tail의 다음 노드는 새로운 노드
    - 새로운 노드가 이제부터 tail
	
```cpp
void linkedList::append(int val) {
    node *newNode = new node(val);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}
```
#### insert() : 추가

- 삽입하려는 위치를 찾는다.
- 해당 위치에 노드를 삽입한다.

> 노드를 삽입할 때 변하는 값을 주의하자

- 맨뒤에 삽입하는 경우 : append() 활용
- 맨앞인 경우 : 
    - 기존 head는 새로운 노드의 다음 노드로 바꿔 주어야 한다.
    - 새로 삽입되는 노드가 head 노드가 된다.
- 나머지 경우 :

    - 새로운 노드의 위치에 있던 노드는 새로운 노드의 다음 노드가 된다.
    - 해당 위치에 있던 노드 이전 노드의 다음 노드는 새로운 노드가 된다.
 

```cpp
insert(int idx, int val) {
    // index 검증
    if (idx < 0 || idx > size) { 
    // index 는 0보다 작거나 크기 보다 클 수 없어요
        cout << "Index Error" << "\n";
        return;
    }
    if (idx == size) {
    	//idx == size -> 맨 뒤
        append(val);
    } else if (idx == 0) {
        node *newNode = new node(val);
        newNode->setNext(head);
        head = newNode;
        updateSize(1);
    } else {
        node *newNode = new node(val);
        node *curNode = head;
        for (int i = 0; i < idx - 1; i++) {
            curNode = curNode->getNext();
        }
        newNode->setNext(curNode->getNext());
        curNode->setNext(newNode);
        updateSize(1);
    }
}
```
#### erase() : 삭제
삭제하려는 위치를 찾는다.
해당 노드를 삭제한다.
- 맨앞 노드를 삭제하는 경우
    - head를 삭제하는 경우
    - 기존 head 다음 노드를 head 로 재정의한다.
- 나머지 경우
    - 삭제하려는 노드의 위치를 찾는다.
    - 삭제하려는 노드의 전 노드의 다음 노드를 삭제하려는 노드의 다음 노드로 바꾼다.
    - 삭제하려는 노드가 tail인 경우 : 
    삭제하려는 노드의 전 노드를 tail로 재정의한다.

```cpp
erase(int idx) {
    if (idx < 0 || idx >= size) { 
    // index 는 0보다 작거나 크기 보다 크거나 같을 수 없어요
        return -1;
    }
    if (empty()) { 
    // 비어있으면 삭제 할 수 없겠죠?
        return -1;
    }
    node *delNode;
    if(idx == 0){
        delNode = head;
        if(size == 0){
            head = nullptr;
        }else{
            head = head->getNext();
        }
    }else{
        node *curNode = head;
        for (int i = 0; i < idx - 1; i++) {
            curNode = curNode->getNext();
        }
        delNode = curNode->getNext();
        curNode->setNext(delNode->getNext());
        if(delNode == tail){
            tail = curNode;
        }
    }
    int val = delNode->getVal();
    delete delNode;
    updateSize(-1);
    return val;
}

```
#### getMin() : 탐색
```cpp
getMin() {
    if (empty()) {
        cout << "empty";
        return;
    }
    int min = head->getVal();
    node *curNode = head;
    for (int i = 0; i < size; i++) {
        if (curNode->getVal() < min)
            min = curNode->getVal();
        curNode = curNode->getNext();
    }
    cout << min;
}

```
#### print() : 탐색
```cpp
print() {
    if (empty()) {
        cout << "empty";
        return;
    }
    node *curNode = head;
    for (int i = 0; i < size; i++) {
        cout << curNode->getVal() << " ";
        curNode = curNode->getNext();
    }
}
```
