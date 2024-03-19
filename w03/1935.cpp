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
int n;
string input;
vector<double> nums;
stack<double> stk;

void init() {
    cin >> n;
    cin >> input;
    while (n--) {
        double num;
        cin >> num;
        nums.emplace_back(num);
    }
}

void solve() {
    int index = 0;
    for (char c: input) {
        if (c >= 'A' && c <= 'Z') {
            stk.push(nums[index]);
            index++;
        } else {
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            if (c == '*') {
                stk.push(b * a);
            } else if (c == '+') {
                stk.push(b + a);
            } else if (c == '-') {
                stk.push(b - a);
            } else {
                stk.push(b / a);
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stk.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    solve();
}
