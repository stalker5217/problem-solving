#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> command;
int dp[100000][5][5];

int moveCost(int source, int target) {
	if(source == 0) return 2; // 원점에서 이동
	else if(source == target) return 1; // 같은 자리
	else if(abs(source - target) == 2) return 4; // 반대 방향
	else return 3; // 인접 방향
}

int getMinValue(int cur, int left, int right) {
	if(cur == command.size()) return 0;

	int& ret = dp[cur][left][right];

	if(ret > 0) return ret;

	int moveLeft = getMinValue(cur + 1, command[cur], right) + moveCost(left, command[cur]);
	int moveRight = getMinValue(cur + 1, left, command[cur]) + moveCost(right, command[cur]);

	ret = min(moveLeft, moveRight);

	return ret; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int cur;
	while(true) {
		cin >> cur;
		if(!cur) break;
		
		command.push_back(cur);
	}

	cout << getMinValue(0, 0, 0);

    return 0;
}