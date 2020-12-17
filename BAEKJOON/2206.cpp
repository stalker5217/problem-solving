#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <queue>

using namespace std;

const int MAX_R = 1000;
const int MAX_C = 1000;
int r, c;

int map[MAX_R][MAX_C];
bool visit[MAX_R][MAX_C][2];

typedef struct __Pos{
	int row;
	int col;
	bool crash;

	__Pos(int __row, int __col, bool __crash)
	: row(__row), col(__col), crash(__crash)
	{}
} Pos;

pair<int, int> dir[4] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

int bfs(Pos);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> r >> c;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			char isWall;
			cin >> isWall;

			map[i][j] = (isWall == '1') ? 1 : 0;
		}
	}
	
	cout << bfs(Pos(0, 0, false));

    return 0;
}

int bfs(Pos start){
	queue<Pos> q;
	q.push(start);
	visit[start.row][start.col][0] = true;

	int dist = 0;
	while(!q.empty()){
		dist++;
		int qSize = q.size();

		for(int i = 0 ; i < qSize ; i++){
			Pos cur = q.front();
			q.pop();
			// cout << cur.row << " " << cur.col << " " << cur.crash << endl;

			if(cur.row == (r-1) && cur.col == (c-1)) return dist;
			
			for(int i = 0 ; i < 4 ; i++){
				int nextR = cur.row + dir[i].first;
				int nextC = cur.col + dir[i].second;
				
				if(nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) continue;
				if(!cur.crash && visit[nextR][nextC][0]) continue;
				if(cur.crash && visit[nextR][nextC][1]) continue;

				if(map[nextR][nextC] == 0){
					if(!cur.crash) visit[nextR][nextC][0] = true; 
					else visit[nextR][nextC][1] = true;
					
					q.push(Pos(nextR, nextC, cur.crash));
				}
				else if(!cur.crash){
					visit[nextR][nextC][1] = true;

					q.push(Pos(nextR, nextC, true));
				}
			}
		}
	}

	return -1;
}