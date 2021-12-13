#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int> > seat(n, vector<int>(n, -1));

	// students.first = 학생 번호
	// students.second = 좋아하는 학생 번호 리스트
	vector<pair<int, vector<int> > > students(n * n);
	for(int s = 0 ; s < n * n ; s++) {
		pair<int, vector<int> >& studentInfo = students[s];
		cin >> studentInfo.first;

		for(int i = 0 ; i < 4 ; i++) {
			int likeYou;
			cin >> likeYou;
			studentInfo.second.push_back(likeYou);
		}
	}
	
	pair<int, int> dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	// 인접한 자리에 좋아하는 학생이 몇 명?
	function<int (vector<int>, pair<int, int>)> getLikeStudentCnt = [&](vector<int> likeInfo, pair<int, int> pos) {
		int cnt = 0;

		for(int i = 0 ; i < 4 ; i++) {
			int row = pos.first + dir[i].first;
			int col = pos.second + dir[i].second;

			if(row >= 0 && row < n && col >= 0 && col < n) {
				if(find(likeInfo.begin(), likeInfo.end(), seat[row][col]) != likeInfo.end()) 
					cnt++;
			}
		}

		return cnt;
	};

	// 비어있는 칸이 몇 개?
	function<int (pair<int, int>)> getEmptySeatCnt = [&](pair<int, int> pos) {
		int cnt = 0;

		for(int i = 0 ; i < 4 ; i++) {
			int row = pos.first + dir[i].first;
			int col = pos.second + dir[i].second;

			if(row >= 0 && row < n && col >= 0 && col < n) {
				if(seat[row][col] == -1) cnt++;
			}
		}

		return cnt;
	};


	for(int s = 0 ; s < students.size() ; s++) {
		auto studentInfo = students[s];
		int maxLikeCnt = -1;
		int thatEmptyCnt = -1;
		pair<int, int> thatPos;
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(seat[i][j] > 0) continue;

				int curCnt = getLikeStudentCnt(studentInfo.second, {i, j});
				if(curCnt > maxLikeCnt) {
					maxLikeCnt = curCnt;
					thatEmptyCnt = getEmptySeatCnt({i, j});
					thatPos.first = i;
					thatPos.second = j;
				}
				else if(curCnt == maxLikeCnt) {
					int emptyCnt = getEmptySeatCnt({i, j});
					if(emptyCnt > thatEmptyCnt) {
						thatEmptyCnt = emptyCnt;
						thatPos.first = i;
						thatPos.second = j;
					}
					else if(emptyCnt == thatEmptyCnt) {
						if(i < thatPos.first) {
							thatPos.first = i;
							thatPos.second = j;
						}
						else if(i == thatPos.first) {
							if(j < thatPos.second) {
								thatPos.second = j;
							}
						}
					}
				}
			}
		}

		seat[thatPos.first][thatPos.second] = studentInfo.first;
	}

	int satisfyScore = 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			pair<int, vector<int> > studentInfo;
			for(int s = 0 ; s < n * n ; s++) {
				if(seat[i][j] == students[s].first) {
					studentInfo = students[s];
					break;
				}
			}
			int likeYouCnt = getLikeStudentCnt(studentInfo.second, {i, j});

			if(likeYouCnt == 1) satisfyScore += 1;
			else if(likeYouCnt == 2) satisfyScore += 10;
			else if(likeYouCnt == 3) satisfyScore += 100;
			else if(likeYouCnt == 4) satisfyScore += 1000;
		}
	}

	cout << satisfyScore;
	return 0;
}