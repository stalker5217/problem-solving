#define DEBUG 0
#define LOG(string) cout << string

#define WALL '*'
#define BLANK '.'
#define DOC '$'

#include <iostream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(int, int, unordered_set<char> &);
bool isNextAvailable(int, int);

int rowSize, colSize;
char map[102][102];
bool visit[102][102];

pair<int, int> dir[4] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	cin >> test_case;
	while(test_case--){
		cin >> rowSize >> colSize;
		for(int i = 1 ; i <= rowSize ; i++){
			for(int j = 1 ; j <= colSize ; j++){
				cin >> map[i][j];
			}
		}
		memset(visit, 0, sizeof(visit));

		for(int i = 0 ; i <= rowSize + 1 ; i++){
			map[i][0] = BLANK;
			map[i][colSize + 1] = BLANK;
		}

		for(int i = 0 ; i <= colSize + 1 ; i++){
			map[0][i] = BLANK;
			map[rowSize + 1][i] = BLANK;
		}

		unordered_set<char> keySet;
		string keyString;
		cin >> keyString;
		for(int i = 0 ; i < keyString.size() ; i++){
			keySet.insert(keyString[i]);
		}

		cout << bfs(0, 0, keySet) << "\n";
	}
    
    return 0;
}

int bfs(int row, int col, unordered_set<char> & keySet){
	int answer = 0;
	
	queue<pair<int, int> > keyWait[26];
	queue<pair<int, int> > q;

	visit[row][col] = true;	
	q.push({row, col});
	
	while(!q.empty()){
		int curRow = q.front().first;
		int curCol = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int nextRow = curRow + dir[i].first;
			int nextCol = curCol + dir[i].second;

			if(isNextAvailable(nextRow, nextCol)){
				visit[nextRow][nextCol] = true;

				// key 획득
				if(map[nextRow][nextCol] >= 'a' && map[nextRow][nextCol] <= 'z'){
					q.push({nextRow, nextCol});
					
					char curKey = map[nextRow][nextCol];
					keySet.insert(curKey);
					while(!keyWait[curKey - 'a'].empty()){
						int r = keyWait[curKey - 'a'].front().first;
						int c = keyWait[curKey - 'a'].front().second;
						keyWait[curKey - 'a'].pop();
						
						q.push({r, c});
					}
				}
				// 문
				else if(map[nextRow][nextCol] >= 'A' && map[nextRow][nextCol] <= 'Z'){
					char needKey = map[nextRow][nextCol] - 'A' + 'a';
					// 키 있음
					if(keySet.find(needKey) != keySet.end()){
						q.push({nextRow, nextCol});
					}
					else{
						keyWait[needKey - 'a'].push({nextRow, nextCol});
					}
				}
				// 문서
				else if(map[nextRow][nextCol] == DOC){
					q.push({nextRow, nextCol});
					answer++;
				}
				// 빈 곳
				else if(map[nextRow][nextCol] == BLANK){
					q.push({nextRow, nextCol});
				}
			}
		}
	}

	return answer;
}

bool isNextAvailable(int row, int col){
	if(row < 0) return false;
	else if(row > rowSize + 1) return false;
	else if(col < 0) return false;
	else if(col > colSize + 1) return false;
	else if(map[row][col] == WALL) return false;
	else if(visit[row][col]) return false;

	return true;
}