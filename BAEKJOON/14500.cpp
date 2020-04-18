#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int rowSize, colSize;
int map[500][500];
int visit[500][500];
int answer = -1;

pair<int, int> dir[4] = {
	make_pair(-1, 0),
	make_pair(0, -1),
	make_pair(1, 0),
	make_pair(0, 1),
};

void dfs(int, int, vector<pair<int, int> > &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> rowSize >> colSize;
	for(int i = 0 ; i < rowSize ; i++){
		for(int j = 0 ; j < colSize ; j++){
			cin >> map[i][j];
		}
	}

	vector<pair<int, int> > visitPos;
	// except fuck
	for(int i = 0 ; i < rowSize ; i++){
		for(int j = 0 ; j < colSize ; j++){
			dfs(i,j,visitPos);
		}
	}

	// 3 2 fuck
	for(int i = 0 ; i < rowSize - 2 ; i++){
		for(int j = 0 ; j < colSize - 1 ; j++){
			int sum1 = 0;
			int sum2 = 0;
			
			sum1 = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
			sum2 = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+1][j];

			int bigger = (sum1 > sum2) ? sum1 : sum2;
			answer = (answer < bigger) ? bigger : answer;
		}
	}

	// 2 3 fuck
	for(int i = 0 ; i < rowSize - 1 ; i++){
		for(int j = 0 ; j < colSize - 2 ; j++){
			int sum1 = 0;
			int sum2 = 0;
			
			sum1 = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
			sum2 = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+1];

			int bigger = (sum1 > sum2) ? sum1 : sum2;
			answer = (answer < bigger) ? bigger : answer;
		}
	}


	cout << answer;

    return 0;
}

void dfs(int r, int c, vector<pair<int, int> > & visitPos){
	if(visitPos.size() == 4){
		int sum = 0;
		for(int i = 0 ; i < visitPos.size() ; i++){
			sum += map[visitPos[i].first][visitPos[i].second];
		}
		answer = (answer < sum) ? sum : answer;

		return;
	}
	for(int i = 0 ; i < 4 ; i++){
		if(r + dir[i].first >= 0
		&& r + dir[i].first < rowSize
		&& c + dir[i].second >= 0
		&& c + dir[i].second < colSize
		&& visit[r+dir[i].first][c+dir[i].second] == 0)
		{
			visitPos.push_back(make_pair(r, c));
			visit[r][c] = 1;
			dfs(r + dir[i].first, c + dir[i].second, visitPos);
			visitPos.pop_back();
			visit[r][c] = 0;
		}
	}
}