# Hash Table

> A hash table is a data structure that implements an associative array, 
> <br>also called a dictionary, which is an abstract data type that maps keys to values.
> <br><br>
> _해시 테이블은 키를 값에 매핑할 수 있는 구조인, 연관 배열 추가에 사용되는 자료 구조이다._

#### what?
개념 부터

### 해시(hash)
```
a dish of chopped meat mixed with potatoes and baked or fried
: 고기와 감자를 잘게 다져 섞어 요리하여 따뜻하게 차려 낸 것
```
- 잘개 쪼개다 
#### 해시 함수
- 임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수

### 해시 테이블
> 임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수를 이용하여 (Key, Value)로 데이터를 저장하는 자료구조 중 하나로 빠르게 데이터를 검색할 수 있는 자료구조
- 내부적으로 배열(버킷)을 사용하여 데이터를 저장
- 각각의 Key값에 해시함수를 적용해 배열의 고유한 index를 생성
- 이 index를 활용해 값을 저장하거나 검색

### 해시 함수
고유한 인덱스 값을 설정하는 함수
- **Division Method**: 나눗셈을 이용하는 방법으로 입력값을 테이블의 크기로 나누어 계산한다.(주소 = 입력값 % 테이블의 크기)<br> h(k) = k % m
  - _테이블의 크기를 소수로 정하고 2의 제곱수와 먼 값을 사용해야 효과가 좋다고 알려져 있다._ (_정수론 내용임 궁금하면 질문하세여_)
- Digit Folding: 각 Key의 문자열을 ASCII 코드로 바꾸고 값을 합한 데이터를 테이블 내의 주소로 사용하는 방법이다. 
- **MAD(Multiply. Add and Divide)** : 숫자로 된 Key값 K와 정수 A,B, 테이블의 크기 m으로 다음과 같은 계산을 해준다.<br>h(k)=(kA + B) % m
- Universal Hashing: 다수의 해시함수를 만들어 집합 H에 넣어두고, 무작위로 해시함수를 선택해 해시값을 만드는 기법이다.

### 결론
- 원본데이터 : val
- 해시함수 : h(x)
- 배열 : arr[]

arr[h(val)] <-- val;

<img src = img.png width = 800>
<img src = img_1.png width = 800>

_thanks for jumin_

### 충돌
원본 데이터를 저장할 index값이 이미 존재하는 경우
- 같은 데이터가 또 추가되는 경우
- 서로 다른 두 키의 해시 값이 같은 경우
  - hash(k1) == hash(k2)

How to solve?

### linear probing : 선형 탐사
- 빈 곳 찾을 때 까지 뒤로 한칸씩 이동
- if(hash(key).exist())
  - hash(key+1)

### quadratic probing : 제곱 탐사
- 빈 곳 찾을 때 까지 i^2 칸 뒤로 이동
  - 처음 ? 1칸 이동
  - 두번째 ? 4칸 이동
  - 세번째 ? 9칸 이동
  - ...
  - if(hash(key).exist())
    - hash(key+i^2)


### double hashing : 이중 해싱
- 해시 함수 두개 쓰기
- 충돌 발생하면 다른 해시 함수로 위치 탐색
- if(hash(key).exist())
  - hash(key + hash2(key))
- ex)

<img src = img_2.png width = 800>

### chaining : 체이닝
- 충돌나면 링리로 이어 붙이기
- 실습때 할일 없으니 개념만 간단히. 수업시간에 제대로 듣기

## 구현

```c++
#define NOITEM 0
#define AVAILABLE 1
#define ISITEM 2
```
- NOITEM : Item이 있던적도 없는 경우
- AVAILABLE : Item이 있다가 없어진 경우
- ISITEM : Item이 있는 경우

### Entry
```c++
class Entry {
private:
    int key;
    string value;
    int valid;
public:
    Entry() { // 기본생성자 : 최초엔 배열에 얘네로 채워둘 예정
        key = 0; 
        value = "";
        valid = NOITEM;
    }

    Entry(int key, string value) { // 생성자 : 유의미한 값이 들어가는 경우
        this->key = key;
        this->value = value;
        this->valid = ISITEM;
    };

    int getKey() { 
        return key;
    }

    string getValue() {
        return value;
    }

    bool isItem() {
        return this->valid == ISITEM;
    }

    bool noItem() {
        return this->valid == NOITEM;
    }

    void erase() {
        this->valid = AVAILABLE;
    }
};
```
## HashTable

```c++
    Entry *table;
    int capacity;

    int hash(int key) {
        return key % capacity;
    }

    HashTable(int n) {
        table = new Entry[n];
        capacity = n;
    }
```
- table : 엔트리 저장될 배열
- capacity : 배열의 최대 크기
- hash () : 해시 함수
- 생성자 : 테이블 동적 할당, 최대 크기 지정

### 데이터 추가
```c++
void put(int k, string s) {
    int idx = hash(k);
    int cnt = 1;
    while (table[idx].isItem() && cnt <= capacity) { 
        idx = hash(idx + 1);
        cnt++;
    }
    Entry *e = new Entry(k, s);
    table[idx] = *e;
}
```
- hash() : 인덱스 구하기
- 충돌 안날때 까지 인덱스 다시 구하기
- 계속 충돌나서 배열 꽉찬 경우 있을 수 있으니 `cnt <= capacity` 조건문 추가
- 엔트리 새로 만들어서 테이블에 추가

### 데이터 탐색
```c++
string find(int k) {
    int idx = hash(k);
    int cnt = 1;
    while (!table[idx].noItem() && cnt <= capacity) {
        if (table[idx].isItem() && table[idx].getKey() == k) {
            return table[idx].getValue();
        }
        idx = hash(idx + 1);
        cnt++;
    }
    return "None";
}
```
- hash() : 인덱스 구하기
- 충돌 날때 까지 인덱스 다시 구하기 : 그 자리에 데이터 있던적 있는지 확인
  - NOITEM만 안됨!
    - AVAILABLE : 찾는 데이터 저장할때 충돌나서 다음거에 저장했다가 그 자리에 있던거 삭제 된 경우엔 idx 다시 구해야 됨
    - ISITEM : 찾는 데이터거나, 찾는 데이터 저장할때 충돌나서 다음거에 저장한 경우엔 idx 다시 구해야됨
  - NOITEM : 찾는거 hash() 한 결과가 생긴적도 없음 반복문 탈출
- 못찾은 경우엔 반복문 탈출

### 데이터 삭제
```cpp
void erase(int k) {
    int idx = hash(k);

    int cnt = 1;
    while (!table[idx].noItem() && cnt <= capacity) {
        if (table[idx].isItem() && table[idx].getKey() == k) {
            cout << table[idx].getValue() << '\n';
            table[idx].erase();
            return;
        }
        idx = hash(idx + 1);
        cnt++;
    }
    cout << "None\n";
}
```
- 삭제시 그냥 해당 엔트리의 valid를 AVAILABLE로 바꿔주면됨


#### 신경쓰기
- 데이터 추가할때 데이터 충돌 안나면 저장하기 
  - table[idx].valid == NOITEM || table[idx].valid == AVAILABLE
- 데이터 찾을 떄, NOITEM 이 아닌경우에 다시 탐색

각 엔트리의 상태(valid)를 점검하고 다루는 것이 중요함!!!!


#### 실습을 위한 추가 지식
string을 해싱 하는 방법

1. 각 소문자를 숫자와 대응시킨다.(a=0,b=1,c=2,...,z=25)
2. 각 자릿수에 맞춰 26진법으로 계산한다. 
   - S[0] x 26^0 +𝑆[1] x 26^1 +𝑆[2] x 26^2 + ...
- EX.
  - string : hello -> 7,4,11,11,14
  - key : 7 * 26^0 + 4 * 26^1 + 11 * 26^2 + 11 * 26^2 + 14 * 26^2
    - 24447
```c++
int pow(int x, int y) {     
    int ans = 1;
    for (int i = 0; i < y; i++) {
        ans *= x;
    }
    return ans;
}
int toInt(string str) {
    int ret = 0;
    for (int i = 0; i < str.length(); i++) {
        ret += (str[i] - 'a') * pow(26, i);
    }
    return ret;
}
```

- 로직들이 이해됐고 구현해볼 자신이 있으면 안보고 구현하기
- 아니면 코드보고 이해안되는 부분 물어보기
- 코드는 외웠는데 왜 그 코드를 썼는지 설명 못하는 경우 많음
- 자기가 짠 코드 한줄 한줄 설명할 수 없으면 이해 못 하고 외운거임
- 제발 이해안되면 물어봐요 제발 제발!! 🙏 😡


<a href = "https://github.com/Landvibe-DataStructure-2024/references/tree/master/%EC%83%98%ED%94%8C%202023-1/week11">문제</a>

<a href = "https://github.com/Landvibe-DataStructure-2024/references/tree/master/2023-1%EC%BD%94%EB%93%9C/w12">코드</a>