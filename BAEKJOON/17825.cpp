#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<int> scores = {
	// 직진 (0 ~ 20)
	0,
	2, 4, 6, 8, 10,
	12, 14, 16, 18, 20,
	22, 24, 26, 28, 30,
	32, 34, 36, 38, 40,

	// 지름길 1 (21 ~ 25)
	10, 
	13, 16, 19, 25,

	// 지름길 2 (26 ~ 29)
	20, 
	22, 24, 25,

	// 지름길 3 (30 ~ 34)
	30, 
	28, 27, 26, 25,

	// 지름길 탈출구 (35 ~ 38)
	25,
	30, 35, 40,
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 주사위 값
	vector<int> dices(10);
	for(int i = 0 ; i < 10 ; i++) cin >> dices[i];

	// 말 위치
	vector<int> positions(4, 0);

	// 현재 방문 여부
	vector<bool> visit(scores.size(), false);

	// DFS
	int answer = -1;
	function<void (int, int)> dfs = [&](int cnt, int sum) {
		if(cnt == 10) {
			answer = max(answer, sum);
			return;
		}

		for(int i = 0 ; i < 4 ; i++) {
			const int curPosition = positions[i];
			// 이미 도착해버린 말
			if(curPosition == -1) continue;

			int dice = dices[cnt];
			int nextPosition = curPosition;
			while(dice--) {
				switch(++nextPosition) {
					case 20:
						nextPosition = 38; break;
					case 25:
					case 29:
					case 34:
						nextPosition = 35; break;
				};
			}

			switch(nextPosition) {
				case 5: 
					nextPosition = 21; break;
				case 10: 
					nextPosition = 26; break;
				case 15: 
					nextPosition = 30; break;
			}

			if(nextPosition >= scores.size()) nextPosition = -1;
			int score = nextPosition == -1 ? 0 : scores[nextPosition];

			if(nextPosition >= 0 && visit[nextPosition]) continue;

			visit[curPosition] = false;
			if(nextPosition >= 0) visit[nextPosition] = true;
			positions[i] = nextPosition; 

			dfs(cnt + 1, sum + score);

			visit[curPosition] = true;
			if(nextPosition >= 0) visit[nextPosition] = false;
			positions[i] = curPosition;
		}
	};

	dfs(0, 0);

	cout << answer;

	return 0;
}