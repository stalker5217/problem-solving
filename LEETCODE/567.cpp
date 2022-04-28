#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> targetHash(26, 0);
        for(int i = 0 ; i < s1.size() ; i++) {
            targetHash[s1[i] - 'a']++;
        }
        
        vector<int> hash(26, 0);
        int s1Length = s1.size();
        for(int i = 0 ; i < s2.size() ; i++) {
            hash[s2[i] - 'a']++;
            if (i - s1Length >= 0) hash[s2[i - s1Length] - 'a']--;
            if (isSameHash(targetHash, hash)) return true;
        }
        
        return false;
    }

private:
    bool isSameHash(vector<int> hash1, vector<int> hash2) {
        for(int i = 0 ; i < hash1.size() ; i++) {
            if (hash1[i] != hash2[i]) return false;
        }
        
        return true;
    }
};