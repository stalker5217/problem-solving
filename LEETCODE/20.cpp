#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool result = true;
		stack<char> st;

		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '(' || s[i] == '{' || s[i] == '['){
				st.push(s[i]);
			}
			else{
				if(st.empty()){
					result = false;
					break;
				}
				else{
					char top = st.top();
					st.pop();
					if(!(
						(top == '(' && s[i] == ')') ||
						(top == '{' && s[i] == '}') ||
						(top == '[' && s[i] == ']')
					))
					{
						result = false;
						break;
					}
				}
			}
		}

		if(!st.empty()) result = false;

		return result;
    }
};