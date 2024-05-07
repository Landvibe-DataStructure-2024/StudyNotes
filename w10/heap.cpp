#include <iostream>
#include <vector>
#include <string>

#define MAX -1
#define MIN 1
#define LAST heapSize

using namespace std;

class Heap {
private:
    vector<int> v;
    int heapSize;
    int rootIndex;
    int dir; // direction 이 1이면 minHeap, -1이면 maxHeap

public:
    Heap(int dir) {
        v.push_back(0);
        heapSize = 0;
        rootIndex = 1;
        this->dir = dir;
    }

    bool compare(int index1, int index2) { // 1번이 우선순위 높으면 true
        return (v[index1] * dir < v[index2] * dir);
    }

    void swap(int index1, int index2) {
        v[0] = v[index1];
        v[index1] = v[index2];
        v[index2] = v[0];
    }

    void upHeap(int index) {
        if (index == rootIndex) {
            return;
        }
        int parent = index / 2;
        if (compare(index, parent)) { // 부모보다 우선순위 높으면 swap
            swap(parent, index);
            upHeap(parent); //바꾼거 기준으로 upHeap
        }
    }

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

    void insert(int i) { // 추가시 맨 뒤 노드부터(방금 추가한 노드)upHeap
        v.push_back(i);
        heapSize++;
        upHeap(LAST);
    }

    int pop() { // 삭제시 맨 마지막에 있는 노드를 루트 노드로 바꾸고 루트 부터 downHeap
        if (isEmpty()) {
            return -1;
        }
        int top = v[rootIndex];
        v[rootIndex] = v[LAST];
        heapSize--;
        v.pop_back();
        downHeap(rootIndex);
        return top;

    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return v[rootIndex];

    }

    int getSize() {
        return heapSize;
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void print() {
        if (isEmpty()) {
            cout << "-1\n";
            return;
        }
        for (int i = rootIndex; i <= heapSize; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

    }
};

