#include <vector>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int min = salary[0];
        int max = salary[0];
        int sum = 0;
        
        for(int cur : salary) {
            if (cur < min) min = cur;
            if (cur > max) max = cur;
            sum += cur;
        }
        
        return (double)(sum - min - max) / (salary.size() - 2);
    }
};