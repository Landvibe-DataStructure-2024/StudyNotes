# 4. 시퀀스 [Sequence]
> <h3>sequence</h3> 
> _noun_ <br> a group of related events or things that have a particular order
<li>연속적인 사건 및 행동들</li>
<li>수열 (수학)</li>

- vector
- list

### vector
aka. arrayList

- 배열의 확장 개념
- index를 통해 접근한다
- Circulary Array :<br> 0 -> 1 -> 2 -> ... -> n-1 -> 0

#### 수행시간
i : index, o : object
- getSize(), isEmpty(), at(i), update(i,o) <br> -> O(1)
- insert(i,o), erase(i) <br> -> O(n)

#### 꽉차면?

더 큰 배열을 만들고 대체한다.
- Incremental strategy : 특정 값을 정해놓고 그만큼씩 늘린다!
- Doubling strategy : 두배로 키운다!

### List
<li> <a href = https://github.com/Landvibe-DataStructure-2024/StudyNotes/blob/main/w02/SinglyLinkedList.md > singly linked list</a> </li>
<li> <a href = https://github.com/Landvibe-DataStructure-2024/StudyNotes/blob/main/w02/DoublyLinkedList.md >doubly linked list</a> </li>
<li> circularly linked list </li>


#### circularly linked list

```
tail->next = head
head->prev = tail
```

#### 수행시간
- getSize(), isEmpty(), remove(), insert() -> O(1) <br> _(※ 위치 정보를 알고 있을 때 )_

![](https://velog.velcdn.com/images/genius00hwan/post/e6aa4eb3-1356-48ed-b0c8-f8a4cd95f8d3/image.png)

### Iterator

sequence의 내부를 순회(traversing)하는 객체

in vector : `(index+1) % size`
in list : `curNode = curNode->next`


#### Iterator 구현
```cpp
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
```
#### 사용 방법
```cpp
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
```

### <a href=https://github.com/Landvibe-DataStructure-2024/StudyNotes/blob/main/w05/sequence.cpp> 전체코드

#### <a href="https://github.com/Landvibe-DataStructure-2024/references/blob/master/%EC%83%98%ED%94%8C%202023-1/week05/prob-W5_P1.pdf"> 문제</a>
#### <a href="https://github.com/Landvibe-DataStructure-2024/references/blob/master/2023-1%EC%BD%94%EB%93%9C/w05/w5p1.cpp">코드</a>