#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) { 
        int sum = 0;
        for(int offset = 0 ; offset < arr.size() ; offset++) {
            int temp = 0;
            for(int i = offset ; i < arr.size() ; i++) {
                temp += arr[i];
                if ((i - offset) % 2 == 0) sum += temp;
            }
        }
        
        return sum;
    }
};