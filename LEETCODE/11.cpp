#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        
        int maxContainerSize = 0;
        while(start <= end){
            int minHeight = height[start] < height[end] ? height[start] : height[end];
            maxContainerSize = max(maxContainerSize, minHeight * (end - start));
            
            if(height[start] < height[end]) start++;
            else end--;
        }
        
        return maxContainerSize;
    }
};