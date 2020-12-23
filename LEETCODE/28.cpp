#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        
		const int haystackSize = haystack.size();
		const int needleSize = needle.size();
		int answer = -1;
        for(int i = 0 ; i <= haystackSize - needleSize ; i++){
			bool isMatched = true;
            for(int j = 0 ; j < needle.size() ; j++){
                if(haystack[i+j] != needle[j]){
                    isMatched = false;
                    break;
                }
            }
            
            if(isMatched){
                answer = i;
                break;
            }
        }
        
        return answer;
    }
};

int main(){
	Solution s;
	cout << s.strStr("", "a");
}