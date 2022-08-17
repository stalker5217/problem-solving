#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> answer;
        int minSum = 2000;
        for (int i = 0 ; i < list1.size() ; i++) {
            for (int j = 0 ; j < list2.size() ; j++) {
                if (list1[i] == list2[j]) {
                    if (i + j < minSum) {
                        minSum = i + j;
                        answer.clear();
                        answer.push_back(list1[i]);
                    } else if (i + j == minSum) {
                        answer.push_back(list1[i]);
                    }
                }
            }
        }
        
        return answer;
    }
};