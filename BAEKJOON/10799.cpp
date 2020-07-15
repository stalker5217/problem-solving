#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string arrangement;
	cin >> arrangement;

	stack<char> mStack;
	int stickCnt = 0;
	for(int i = 0 ; i < arrangement.size() ; i++){
		if(arrangement[i] == '(') mStack.push(arrangement[i]);
		else{
			// Razer
			if(i - 1 >= 0 && arrangement[i-1] == '('){
				mStack.pop();
				stickCnt += mStack.size();
			}
			// Stick
			else{
				mStack.pop();
				stickCnt++;
			}
		}
	}

	cout << stickCnt;
    
    return 0;
}