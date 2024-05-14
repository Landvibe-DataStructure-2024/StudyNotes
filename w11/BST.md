# Binary Search Tree (이진 탐색 트리)

> binary search tree is a rooted binary tree data structure with the key of each internal node being greater than
> all the keys in the respective node's left subtree and less than the ones in its right subtree.
>
> _이진 탐색 트리 : 어떤 내부 노드에 대해 왼쪽 서브 트리의 노드들의 키값은 다 작고, 오르쪽 서브트리의 노드들 의 키값은 다 큰 트리_

### 기능

- 탐색 : Avg : O(logn)/ worst : O(n)
- 추가 : Avg : O(logn)/ worst : O(n)
- 삭제 : Avg : O(logn)/ worst : O(n)

<a href = "https://www.cs.usfca.edu/~galles/visualization/BST.html"> 시뮬레이션 </a>

### 탐색

- 루트 부터 시작
- 탐색할 노드가 없을 때 까지 반복
    - target == curNode.val
      return curNode
    - target < curNode.val
      curNode <- curNode.left
    - target > curNode.val
      curNode <- curNode.right

### 삽입

- 새로운 노드 생성
- 삽입할 위치 **탐색**
    - target < curNode.val
      curNode <- curNode.left
    - target > curNode.val
      curNode <- curNode.right
- 해당 위치에 노드 삽입

### 삭제

- 삭제할 노드 위치 **탐색**
- 자식 노드의 개수에 따라 3가지 경우로 나눔
    - 0개 : 그냥 삭제
    - 1개 : 삭제할 노드의 자식 노드를 삭제할 노드 위치로 이동
        - root 인 경우 : 삭제하고 한 자식을 새로운 root로
        - child.par <- delNode.par
        - delNode.par.child <- delNode.child
            - 내가 부모의 어떤 자식인지가 중요
            - 왼쪽 자식 : 삭제할 노드의 자식도 삭제할 노드의 부모보다 작음
                - delNode.par.leftChild <- delNode.child
            - 오른쪽 자식 : 삭제할 노드의 자식도 삭제할 노드의 부모보다 큼
                - delNode.par.rightChild <- delNode.child
    - 2개 :
        - 삭제할 노드의 오른쪽 서브트리중 가장 왼쪽에 있는 노드 찾기
          <br> _(나보다 큰 녀석중 가장 작은 녀석)_
          > **successor** <br> 주어진 노드의 키보다 큰 키를 가진 노드 중 가장 작은 키를 가진 노드
        - succ을 삭제할 노드의 위치로
        - succ가 왼쪽 자식인 경우
            - succ.par.leftChild <- succ.rightChild
                - succ이 부모보다 작음
                - succ보다 succ.right이 더큼
        - succ가 오른쪽 자식인 경우
            - succ.par.rightChild <- succ.rightChild
                - succ이 부모보다 더 큼

## 구현

#### 탐색

```cpp
Node *find(int val) {
    Node *curNode = root;
    while (curNode->val != val) {
        if (val < curNode->val) {
            if (curNode->left->isDummy()) return curNode;
            curNode = curNode->left;
        } else {
            if (curNode->right->isDummy()) return curNode;
            curNode = curNode->right;
        }
    }
    return curNode;
}
```

#### 삽입

```cpp
void insert(int val) {
    Node *newNode = new Node(val);
    if (size == 0) {
        root = newNode;
    } else {
        Node *parent = find(val);
        if (val < parent->val) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        newNode->parent = parent;
    }
    size++;
}
```

#### 삭제

```cpp
void erase(int val) {
    Node *delNode = find(val);
    Node *parNode = delNode->parent;
    if (delNode->left->isDummy() && delNode->right->isDummy()) {// 자식이 0
        if (delNode == root) { // 지울 노드가 root인 경우
            this->root = new Node();
        } else {
            if (delNode == parNode->left) {
                parNode->left = new Node();
            } else if (delNode == parNode->right) {
                parNode->right = new Node();
            }
        }
    } else if (delNode->left->isDummy() || delNode->right->isDummy()) { // 자식이 1
        Node *child = (delNode->left->isDummy()) ? delNode->right : delNode->left;
        // 왼쪽이 dummy면 오른쪽, 아니면 왼쪽
        if (delNode == root) { // 지울 노드가 root인 경우
            this->root = child;
        } else {
            if (delNode == parNode->left) { // 지울 노드가 왼쪽 자식이면
                parNode->left = child; // 부모 왼쪽에 child
            } else if (delNode == parNode->right) {
                parNode->right = child; // 부모 오른쪽에 child
            }
        }
    } else { // 자식이 2
        Node *succ = delNode->right;
        Node *succPar = delNode;
        while (!succ->left->isDummy()) { // succ 찾기(오른쪽 subtree중 제일 왼쪽에 있는 노드)
            succPar = succ;
            succ = succ->left;
        }

        if (succ == succPar->left) { // succ이 왼쪽 자식이면
            succPar->left = succ->right; // 부모의 왼쪽 <- succ의 오른쪽
        } else {
            succPar->right = succ->right;  // 부모의 오른쪽 <- succ의 오른쪽
        }

        delNode->val = succ->val;
        delNode = succ;
    }
    size--;
    delete delNode;
}
```

전체코드