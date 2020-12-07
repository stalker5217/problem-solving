#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct PosInfo{
	int row;
	int col;
	int visitBit = 0;
};

int rowSize, colSize;
char map[20][20];

pair<int, int> dir[4] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int bfs();
PosInfo makePosInfo(int, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> rowSize >> colSize;
	for(int i = 0 ; i < rowSize ; i++){
		for(int j = 0 ; j < colSize ; j++){
			cin >> map[i][j];
		}
	}

	cout << bfs();
	
    return 0;
}

int bfs(){
	queue<PosInfo> q;
	q.push(makePosInfo(0, 0, 0));

	int lastBit = 0;
	while(!q.empty()){
		PosInfo curPos = q.front();
		lastBit = curPos.visitBit;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int nextRow = curPos.row + dir[i].first;
			int nextCol = curPos.col + dir[i].second;

			bool isBoundary = true;
			isBoundary &= (nextRow >= 0 && nextRow < rowSize);
			isBoundary &= (nextCol >= 0 && nextCol < colSize);
			if(!isBoundary) continue;

			PosInfo newPos = makePosInfo(nextRow, nextCol, curPos.visitBit);
			if(newPos.visitBit == -1) continue;
			
			q.push(newPos);
		}
	}

	int cnt = 0;
	while(lastBit){
		if(lastBit & 1) cnt++;
		lastBit >>= 1;
	}

	return cnt;
}

PosInfo makePosInfo(int row, int col, int visitBit){
	int curBit = 1;
	curBit <<= (map[row][col] - 'A');
	// 이미 방문
	if((curBit & visitBit) != 0){
		PosInfo fail;
		fail.visitBit = -1;
		return fail;
	}

	PosInfo cur;
	cur.row = row;
	cur.col = col;
	cur.visitBit = visitBit | curBit;

	return cur;
}