#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> exclude;
        stack<pair<char, int>> st;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == '(') {
                st.push({'(', i});
            } else if (s[i] == ')') {
                if (!st.empty() && st.top().first == '(') {
                    st.pop();
                } else {
                    exclude.push_back(i);
                }
            }
        }

		vector<int> remain;
		while (!st.empty()) {
			remain.push_back(st.top().second);
			st.pop();
		}
		reverse(remain.begin(), remain.end());

        exclude.insert(exclude.end(), remain.begin(), remain.end());

        string answer = "";
        int excludeIndex = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (excludeIndex < exclude.size() && exclude[excludeIndex] == i) {
                excludeIndex++;
            } else {
                answer += s[i];
            }
        }

        return answer;
    }
};