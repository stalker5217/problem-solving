// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long first = 1;
        long long last = n;
        
        while(first <= last){
            long long mid = (first + last) / 2;
            if(isBadVersion(mid)) last = mid - 1;
            else first = mid + 1;
        }
        
        return first;
    }  
};