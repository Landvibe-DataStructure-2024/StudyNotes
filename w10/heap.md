# HEAP (Priority Queue)
> 힙(heap)은 최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안된 완전이진트리(complete binary tree)를 기본으로 한 자료구조(tree-based structure)로서 다음과 같은 힙 속성(property)을 만족한다.
> <br> - A가 B의 부모노드(parent node) 이면, A의 키(key)값과 B의 키값 사이에는 대소관계가 성립한다.
> <br> 힙에는 두가지 종류가 있으며, 부모노드의 키값이 자식노드의 키 값보다 항상 큰 힙을 '최대 힙', 부모노드의 키 값이 자식노드의 키 값보다 항상 작은 힙을 '최소 힙'이라고 부른다.
> <br> 키 값의 대소관계는 오로지 부모노드와 자식노드 간에만 성립하며, 특히 형제 사이에는 대소관계가 정해지지 않는다.

- **부모가 자식보다 우선순위가 높다.**
  - 루트 노드 : 가장 우선순위가 높은 노드
  - 최대, 최소값을 빠르게 찾을 수 있다.
- 일반적으로 완전 이진트리로 구성된다. 
- 우선순위큐를 구현하는데에 사용된다. 

<a href = http://btv.melezinek.cz/binary-heap.html >heap simulation</a>
### Push
- 맨 뒤에 노드 추가
- 부모보다 우선 순위 높으면 swap
  - 적합한 구조를 가질 때 까지 swap 하며 올라감 -> upHeap

### Pop
- 루트 노드랑 마지막 노드 swap
  - 마지막 노드 삭제
- 루트에 적합한 값이 들어 있지 않음 
  - 자식보다 우선 순위 낮으면 swap
  - 적합한 구조를 가질 때 까지 swap 하며 내려감 -> downHeap

### upHeap
지금 노드에서 올라가면서 heap을 재구성하기
```c++
void upHeap(int index) {
    if (index == rootIndex) {
        return;
    }
    int parent = index / 2;
    if (compare(index, parent)) { // 부모보다 우선순위 높으면 swap
        swap(parent, index);
        upHeap(parent); // 바꾼거 기준으로 upHeap
    }
}
```
- 루트 까지 가면 종료
- 부모노드보다 우선순위 낮으면(적합한 구조) 종료

### downHeap
지금 노드부터 내려가면서 Heap 재구성
```c++
void downHeap(int index) {
    int lChild = index * 2;
    int rChild = index * 2 + 1;
    if (rChild <= LAST) { // 자식이 둘인 경우
        if (compare(lChild, rChild)) { // 왼쪽 자식이 오른쪽 자식 보다 우선순위 높은 경우
            if (compare(lChild, index)) { // 왼쪽 자식이 우선순위 높으면 swap
                swap(lChild, index);
                downHeap(lChild); // 바꾼거 기준으로 downHeap
            }
        } else { // 오른쪽 자식이 왼쪽 자식 보다 우선순위 높은 경우
            if (compare(rChild, index)) {  // 오른쪽 자식이 우선순위 높으면 swap
                swap(rChild, index);
                downHeap(rChild);// 바꾼거 기준으로 downHeap
            }
        }
    } else if (lChild <= LAST) { // 자식이 하나인 경우
        if (compare(lChild, index)) { //자식이 우선순위 높으면 swap
            swap(lChild, index);
            downHeap(lChild);// 바꾼거 기준으로 downHeap
        }
    }
}
```
- 자식이 없으면 종료
- 자식 노드보다 우선순위 높으면 (적합한 구조) 종료

### 복잡도 : O(log n)
![img.png](img.png)
![img_1.png](img_1.png)

<a href="https://github.com/Landvibe-DataStructure-2024/references/blob/f20ad3bfaee468be72e3056182c525dc61bec52a/%EC%83%98%ED%94%8C%202023-1/week10/prob-W10_P1.pdf"> 문제 1</a>
<br>
최소 힙 만들어서 넣고 빼고 하는 문제 
<br>
<a href="https://github.com/Landvibe-DataStructure-2024/references/blob/f20ad3bfaee468be72e3056182c525dc61bec52a/2023-1%EC%BD%94%EB%93%9C/w10/w10p1.cpp">코드 1</a>
<br>


지금부터 이거 풀기 : <br>
<a href="https://github.com/Landvibe-DataStructure-2024/references/blob/f20ad3bfaee468be72e3056182c525dc61bec52a/%EC%83%98%ED%94%8C%202023-1/week10/prob-W10_P2.pdf"> 문제 2</a>


