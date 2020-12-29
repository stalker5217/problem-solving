#include <string>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

		int start = 0, end = 0;
		int length = 0;
		int answer = 0;
		while(start <= end && end < s.size()){
			if(charSet.find(s[end]) == charSet.end()){
				charSet.insert(s[end++]);
				length++;
				answer = max(answer, length);
			}
			else{
				charSet.erase(s[start++]);
				length--;
			}
		}

		return answer;
    }
};

int main(){
	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew");
}