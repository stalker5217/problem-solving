#include <queue>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1 ; i <= n ; i++) {
            q.push(i);
        }

		int lastGuy = -1;
		while (!q.empty()) {
			int count = k;
			while (count--) {
				int temp = q.front();
				q.pop();
				q.push(temp);
			}

			lastGuy = q.front();
			q.pop();
		}

		return lastGuy;
    }
};