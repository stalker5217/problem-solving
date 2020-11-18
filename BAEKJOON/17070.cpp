#include <iostream>
#include <vector>

#define EMPTY 0
#define WALL 1

#define H 0 // 가로
#define V 1 // 세로
#define D 2 // 대각

using namespace std;

const int MAX_N = 16;
int n;
int map[MAX_N][MAX_N];
int cnt = 0;

pair<int, int> dir[3] = {
	{0, 1},
	{1, 0},
	{1, 1}
};
vector<pair<int, int> > visit;

void dfs(int, int, int);

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}

	dfs(0, 1, H);

	cout << cnt;

	return 0;
}

void dfs(int row, int col, int preShape){
	if(row == (n-1) && col == (n-1)){
		cnt++;
		return;
	}

	for(int i = 0 ; i < 3 ; i++){
		if(row + dir[i].first >= 0 &&
		   row + dir[i].first < n &&
		   col + dir[i].second >= 0 &&
		   col + dir[i].second < n &&
		   map[row + dir[i].first][col + dir[i].second] == 0 &&
		   !(i == H && preShape == V) &&
		   !(i == V && preShape == H) &&
		   !(i == D && map[row + dir[i].first][col]) &&
		   !(i == D && map[row][col + dir[i].second]))
		{
			{
				dfs(row + dir[i].first, col + dir[i].second, i);
			}
		}
	}
}