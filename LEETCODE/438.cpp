#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        if (s.size() < p.size()) {
            return answer;
        }
        
        vector<int> target(26);
        vector<int> freq(26);
        for(int i = 0 ; i < p.size() ; i++) {
            target[p[i] - 'a']++;
            freq[s[i] - 'a']++;
        }
        
        pair<int, int> points = {0, p.size()};
        while(true) {
            if (target == freq) {
                answer.push_back(points.first);
            }
            
            if (points.second == s.size()) {
                break;
            }
            
            freq[s[points.first++] - 'a']--;
            freq[s[points.second++] - 'a']++;
        }
        
        return answer;
    }
};