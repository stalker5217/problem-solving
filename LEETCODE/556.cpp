#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string numString = to_string(n);
        // 2147483476
        for(int i = numString.size() - 2; i >= 0 ; i--) {
            if (numString[i] < numString[i+1]) {
                for(int j = numString.size() - 1 ; j > i ; j--) {
                    if (numString[i] < numString[j]) {
                        swap(numString[i], numString[j]);
                        reverse(numString.begin() + i + 1, numString.end());
                        
                        long long answer = stol(numString);
                        return answer <= INT32_MAX ? answer : -1; 
                    }
                }                
            }
        }
        
        return -1;
    }
};