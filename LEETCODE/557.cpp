#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> splitList = split(s, ' ');
        
        string answer = "";
        for(string cur : splitList) {
            reverse(cur.begin(), cur.end());
            toupper(cur[cur.size() - 1]);
            answer += cur;
            answer += " ";
        }
        
        
        return answer.substr(0, answer.size() - 1);
    }

private:
    vector<string> split(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }

        return answer;
    }
};