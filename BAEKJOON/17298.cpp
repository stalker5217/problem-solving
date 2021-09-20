#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n, 0);
    for(int i = 0 ; i < n ; i++) cin >> seq[i];

    vector<int> answer(n, -1);
    stack<int> mStack;
    for(int i = 0 ; i < n ; i++) {
        while(!mStack.empty() && seq[mStack.top()] < seq[i]) {
            answer[mStack.top()] = seq[i];
            mStack.pop();
        }

        mStack.push(i);
    }

    for(int cur : answer) cout << cur << " ";

    return 0;
};