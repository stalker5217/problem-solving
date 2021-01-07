#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_R = 100;
const int MAX_C = 100;

int r, c;

int map[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];

pair<int, int> dir[4] = {
	{0, 1},
	{1, 0},
	{-1, 0},
	{0, -1}
};

void dfs(int, int);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	int cheeseCnt = 0;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> map[i][j];
			if(map[i][j]) cheeseCnt++;
		}
	}

	int time = 0;
	while(true){
		if(cheeseCnt <= 0) break;
		
		memset(visited, 0, sizeof(visited));
		visited[0][0] = true;
		dfs(0, 0);

		time++;
		// 사라지는 치즈 검사
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				if(map[i][j] == 2) map[i][j] = 1;
				else if(map[i][j] > 2){
					map[i][j] = 0;
					cheeseCnt--;
				}
			}
		}
	}

	cout << time;

	return 0;
}

void dfs(int row, int col){
	for(int i = 0 ; i < 4 ; i++){
		int nextRow = row + dir[i].first;
		int nextCol = col + dir[i].second;

		if(nextRow >= 0 && nextRow < r && nextCol >= 0 && nextCol < c){
			if(map[nextRow][nextCol] == 0 && !visited[nextRow][nextCol]){
				visited[nextRow][nextCol] = true;
				dfs(nextRow, nextCol);
			}
			else if(map[nextRow][nextCol] > 0){
				map[nextRow][nextCol] += 1;
			}
		}
	}
}