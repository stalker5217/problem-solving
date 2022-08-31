#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n - 1;
        int b = 1;
        
        while(hasZero(a) || hasZero(b)) {
            a--;
            b++;
        }
        
        vector<int> answer(2);
        answer[0] = a;
        answer[1] = b;
        
        return answer;
    }
    
    bool hasZero(int n) {
        while(n > 0) {
            if (n % 10 == 0) {
                return true;
            }
            
            n /= 10;
        }
        
        return false;
    }
};