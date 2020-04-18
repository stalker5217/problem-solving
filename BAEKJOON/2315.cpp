#define DEBUG 0
#define LOG(string) cout << string

#define MAX_CNT 1000
#define INF 987654321

#define LEFT 0
#define RIGHT 1

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int lampCnt, startPos;
int lampPos[MAX_CNT + 1];
int watt[MAX_CNT + 1];
int wattSum[MAX_CNT + 1];
int dp[MAX_CNT + 1][MAX_CNT + 1][2];

int solution(int, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	
	cin >> lampCnt >> startPos;

	for(int i = 1 ; i <= lampCnt ; i++){
		int _pos, _watt;
		cin >> _pos >> _watt;
		
		lampPos[i] = _pos;
		watt[i] = _watt;
		wattSum[i] = wattSum[i-1] + _watt;
	}

	memset(dp, -1 , sizeof(dp));
	int answer = solution(startPos, startPos, 0);
	cout << answer;

    return 0;
}

/**
 * dp[L][R][0] = L~R을 탐색하고 Left에 위치했을 때
 * dp[L][R][1] = L~R을 탐색하고 Right에 위치했을 때
 */
int solution(int left, int right, int flag){
	if(left <= 1 && right >= lampCnt) return 0;
	if(dp[left][right][flag] != -1) return dp[left][right][flag];

	int answer = INF;
	if(left - 1 >= 1){
		int now = (flag == LEFT) ? left : right;
		int dis = lampPos[now] - lampPos[left - 1];
		int wattPerM = wattSum[lampCnt] - wattSum[right] + wattSum[left-1];
		int result = solution(left - 1 , right, 0) + (dis * wattPerM);
		answer = min(result, answer);
	}

	if(right + 1 <= lampCnt){
		int now = (flag == LEFT) ? left : right;
		int dis = lampPos[right + 1] - lampPos[now];
		int wattPerM = wattSum[lampCnt] - wattSum[right] + wattSum[left-1];
		int result = solution(left , right + 1, 1) + (dis * wattPerM);
		answer = min(result, answer);
	}

	if(DEBUG) cout << left << " ~ " << right << " : " << answer <<"\n";

	dp[left][right][flag] = answer;
	return answer;
}