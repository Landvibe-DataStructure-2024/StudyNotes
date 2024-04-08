### vector 사용법

지난주 배운 vector를 구현해놓은 stl

### 선언
vector<int> v;
- 비어있는 vector v를 생성

vector<int> v(5);
- 기본값(0)으로 초기화 된 5개의 원소를 가지는 vector v를 생성

### 함수들
push_back(), emplace_back() 
- 기본적인 동작 방식은 같음
- 맨 뒤에 데이터를 추가하는 함수

insert(i, a)
- i번째 위치에 a의 값을 삽입합니다.
- 삽입한 곳의 iterator를 반환합니다.

pop_back()
- 마지막 원소를 제거

clear()
- 모든 원소를 제거
- 원소만 제거하고 메모리는 남아있다.

front()
- 첫번째 원소를 참조

at(i)
 - i번째 원소를 참조
 - 범위를 점검하므로 안전

v[i]
- idx번째 원소를 참조
- 범위를 점검하지 않음
- 속도가 v.at(i)보다 빠름