#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int mostBooked(const int n, vector<vector<int>> meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> availableRoom;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usingRoom;
        vector<int> count(n, 0);

        for(int i = 0 ; i < n ; i++) {
            availableRoom.push(i);
        }

        for(auto & meeting : meetings) {
            // 끝난 회의 릴리즈
            while(!usingRoom.empty() && usingRoom.top().first <= meeting[0]) {
                int roomNumber = usingRoom.top().second;

                usingRoom.pop();
                availableRoom.push(roomNumber);
            }

            if (availableRoom.empty()) { // 비어 있는 경우에는 대기 후 진행
                long long endTime = usingRoom.top().first;
                int assign = usingRoom.top().second;

                usingRoom.pop();
                usingRoom.push({meeting[1] - meeting[0] + endTime, assign});
                count[assign]++;
            } else {
                int assign = availableRoom.top();

                availableRoom.pop();
                usingRoom.push({meeting[1], assign});
                count[assign]++;
            }
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};