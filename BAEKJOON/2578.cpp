#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int> > board(5, vector<int>(5));
	for(int i = 0 ; i < 5 ; i++) {
		for(int j = 0 ; j < 5 ; j++) {
			cin >> board[i][j];
		}
	}

	for(int p = 1 ; p <= 25 ; p++) {
		int cur; cin >> cur;

		// 현재 숫자를 찾아 지움
		for(int i = 0 ; i < 5 ; i++) {
			for(int j = 0 ; j < 5 ; j++) {
				if(board[i][j] == cur) {
					board[i][j] = -1;
				}
			}
		}

		int bingo = 0;
		// 가로 빙고
		for(int i = 0 ; i < 5 ; i++) {
			bool isBingo = true;
			for(int j = 0 ; j < 5 ; j++) {
				if(board[i][j] > 0) {
					isBingo = false;
					break;
				}
			}
			if(isBingo) bingo++;
		}

		// 세로 빙고
		for(int j = 0 ; j < 5 ; j++) {
			bool isBingo = true;
			for(int i = 0 ; i < 5 ; i++) {
				if(board[i][j] > 0) {
					isBingo = false;
					break;
				}
			}
			if(isBingo) bingo++;
		}

		// 대각선 빙고
		bool isBingo = true;
		for(int i = 0 ; i < 5 ; i++) {
			if(board[i][i] > 0) {
				isBingo = false;
				break;
			}
		}
		if(isBingo) bingo++;

		// 대각선 빙고
		isBingo = true;
		for(int i = 0 ; i < 5 ; i++) {
			if(board[i][4-i] > 0) {
				isBingo = false;
				break;
			}
		}
		if(isBingo) bingo++;

		if(bingo >= 3) {
			cout << p;
			break;
		}
	}

	return 0;
}