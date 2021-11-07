#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct __query {
	string num;
	int strike;
	int ball;
} Query;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<Query> queries(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> queries[i].num;
		cin >> queries[i].strike;
		cin >> queries[i].ball;
	}
	
	int answer = 0;
	for(int i = 123 ; i <= 987 ; i++) {
		string cur = to_string(i);

		// 중복 숫자 체크
		if(cur[0] == cur[1] || cur[0] == cur[2] || cur[1] == cur[2]) continue;
		
		// 0 체크
		if(cur[0] == '0' || cur[1] == '0' || cur[2] == '0') continue;

		bool isPossible = true;
		for(int q = 0 ; q < queries.size() ; q++) {
			int curStrike = 0;
			int curBall = 0;

			// 스트라이크 체크
			for(int a = 0 ; a < 3 ; a++) if(queries[q].num[a] == cur[a]) curStrike++;
			
			// 볼 체크
			for(int a = 0 ; a < 3 ; a++) {
				for(int b = 0 ; b < 3 ; b++) {
					if(a == b) continue;
					if(queries[q].num[a] == cur[b]) curBall++;
				}
			}

			if(queries[q].strike != curStrike || queries[q].ball != curBall) {
				isPossible = false;
				break;
			}
		}

		if(isPossible) answer++;
	}

	cout << answer;

	return 0;
}