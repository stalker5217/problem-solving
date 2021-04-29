#include <vector>

using namespace std;

class Solution {
private:
    vector<string> containString = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> answer;
    
public:
    vector<string> letterCombinations(string digits) {
        helper(digits, 0, "");
        return answer;
    }
    
    void helper(string digits, int digitsIndex, string temp){
        if(digits.size() == digitsIndex){
            if(!temp.empty()) answer.push_back(temp);
            return;
        }
        
        int curNumber = digits[digitsIndex] - '0';
        for(int i = 0 ; i < containString[curNumber].size() ; i++){
            temp.push_back(containString[curNumber][i]);
            helper(digits, digitsIndex + 1, temp);
            temp.pop_back();
        }
    }
};