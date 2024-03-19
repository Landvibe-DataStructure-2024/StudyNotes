#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

#define INF 987654321

using namespace std;
string str;
stack<char> stk;

void init(){
    cin >> str;
}
void solve(){
    for (char c: str) {
        if (c >= 'A' && c <= 'Z') {
            stk.push(c);
        } else if (c == '(') {
            stk.push(c);
        } else if (c == '*' || c == '/') {
            while (!stk.empty() && stk.top() != '(') {
                if (stk.top() >= 'A' && stk.top() <= 'Z') {
                    cout << stk.top();
                    stk.pop();
                } else if (stk.top() == '*' || stk.top() == '/') {
                    cout << stk.top();
                    stk.pop();
                } else {
                    break;
                }
            }
            stk.push(c);
        } else if (c == '+' || c == '-') {
            while (!stk.empty() && stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
        } else if (c == ')' && !stk.empty()) {
            while (!stk.empty() && stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }
            stk.pop();
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    solve();
}
