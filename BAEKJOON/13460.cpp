#define DEBUG 0
#define LOG(string) cout << string

#define NONE 0
#define BRICK 1
#define RED 2
#define BLUE 3
#define HOLE 4

#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
int map[10][10];
int originMap[10][10];

int moveBall(int color, int dir);
void game(int);

vector<int> dirVector;
int tryCnt;

pair<int, int> direction[4] = {
	make_pair(0, 1), // 동
	make_pair(0, -1), // 서
	make_pair(1, 0), // 남
	make_pair(-1, 0), // 북
};

pair<int, int> bluePosOrigin;
pair<int, int> redPosOrigin;
pair<int, int> bluePos;
pair<int, int> redPos;

bool possible = false;
int minCnt = 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			char temp;
			cin >> temp;
			if(temp == '#'){
				originMap[i][j] = BRICK; // 벽
			}

			else if(temp == 'B'){
				originMap[i][j] = BLUE;
				bluePosOrigin = make_pair(i,j);
			}

			else if(temp == 'R'){
				originMap[i][j] = RED;
				redPosOrigin = make_pair(i,j);
			}

			else if(temp == 'O'){
				originMap[i][j] = HOLE;
			}
		}
	}
    
	game(0);

	if(possible){
		cout << minCnt;
	}
	else{
		cout << -1;
	}

    return 0;
}

int moveBall(int color, int dir){
	int curRow;
	int curCol;

	if(color == BLUE){
		curRow = bluePos.first;
		curCol = bluePos.second;
		map[curRow][curCol] = NONE;
	}
	else if(color == RED){
		curRow = redPos.first;
		curCol = redPos.second;
		map[curRow][curCol] = NONE;
	}

	int dirRow = direction[dir].first;
	int dirCol = direction[dir].second;

	while(1){
		if(map[curRow + dirRow][curCol + dirCol] == NONE){
			curRow += dirRow;
			curCol += dirCol;
		}
		else if(map[curRow + dirRow][curCol + dirCol] != HOLE){
			map[curRow][curCol] = color;
			if(color == BLUE){
				bluePos.first = curRow;
				bluePos.second = curCol;
			}
			else if(color == RED){
				redPos.first = curRow;
				redPos.second = curCol;
			}
			return map[curRow + dirRow][curCol + dirCol]; // 벽 꿍
		}
		else{
			return map[curRow + dirRow][curCol + dirCol]; // 구멍
		}
	}
}

void game(int tryCnt){
	// escape condition
	if(tryCnt >= minCnt){
		bool isSuccess = false;
		int resultCnt;

		for(int i = 0 ; i < N ; i++){
			memcpy(map[i], originMap[i], sizeof(int) * M);
		}

		bluePos = make_pair(bluePosOrigin.first, bluePosOrigin.second);
		redPos = make_pair(redPosOrigin.first, redPosOrigin.second);

		for(int i = 0 ; i < dirVector.size() ; i++){
			int blueResult, redResult;
			if(dirVector[i] == EAST){
				// 오른쪽에 있는거 먼저
				if(bluePos.second < redPos.second){
					redResult = moveBall(RED, EAST);
					blueResult = moveBall(BLUE, EAST);
				}
				else{
					blueResult = moveBall(BLUE, EAST);
					redResult = moveBall(RED, EAST);
				}
			}
			else if(dirVector[i] == WEST){
				if(bluePos.second > redPos.second){
					redResult = moveBall(RED, WEST);
					blueResult = moveBall(BLUE, WEST);
				}
				else{
					blueResult = moveBall(BLUE, WEST);
					redResult = moveBall(RED, WEST);
				}
			}
			else if(dirVector[i] == SOUTH){
				if(bluePos.first < redPos.first){
					redResult = moveBall(RED, SOUTH);
					blueResult = moveBall(BLUE, SOUTH);
				}
				else{
					blueResult = moveBall(BLUE, SOUTH);
					redResult = moveBall(RED, SOUTH);
				}
			}
			else if(dirVector[i] == NORTH){
				if(bluePos.first > redPos.first){
					redResult = moveBall(RED, NORTH);
					blueResult = moveBall(BLUE, NORTH);
				}
				else{
					blueResult = moveBall(BLUE, NORTH);
					redResult = moveBall(RED, NORTH);
				}
			}

			if(blueResult == HOLE){
				break;
			}
			else if(redResult == HOLE){
				isSuccess = true;
				resultCnt = i + 1;
				break;
			}
		}

		if(isSuccess){
			if(resultCnt <= minCnt){
				possible = true;
				minCnt = resultCnt;
			}
		}
		
		return;
	}

	for(int i = 0 ; i < 4 ; i++){
		dirVector.push_back(i);
		game(tryCnt+1);
		dirVector.pop_back();
	}
}