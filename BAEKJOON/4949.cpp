#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(true){
		string text;
		getline(cin, text);
		if(text.compare(".") == 0){
			break;
		}
		
		stack<char> mStack;
		bool result = true;
		for(int i = 0 ; i < text.length() ; i++){
			if(text[i] == '[' || text[i] == '('){
				mStack.push(text[i]);
			}
			else if(text[i] == ']' || text[i] == ')'){
				if(mStack.empty()){
					result = false;
					break;
				}
				else{
					if(text[i] == ']' && mStack.top() == '['){
						mStack.pop();
					}
					else if(text[i] == ')' && mStack.top() == '('){
						mStack.pop();
					}
					else{
						result = false;
						break;
					}
				}
			}
		}
		if(result && mStack.size() == 0){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
    
    return 0;
}
