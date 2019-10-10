#define DEBUG 0
#define LOG(string) cout << string

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __pos{
	int r;
	int c;
	int dir;
	int rotateCnt;
} pos;

int whatIsLeftSide(int dir);
int whatIsReverseSide(int dir);
int cleanMap();

int map[50][50];
int N, M;
pos robotPos;

pair<int, int> dirArr[] = {
	make_pair(-1, 0),
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1)
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    cin >> N >> M;
	int temp;
	cin >> robotPos.r >> robotPos.c >> robotPos.dir;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> map[i][j];
		}
	}
    
	while(true){
		if(cleanMap() == 4)
			break;
	}

	int cleanCnt=0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i][j] == 2){
				cleanCnt++;
			}
		}
	}

	cout << cleanCnt;

    return 0;
}

int whatIsLeftSide(int dir){
	if(dir > 0){
		return dir-1;
	}
	else if(dir == 0){
		return WEST;
	}
	else{
		return -1;
	}
}

int whatIsReverseSide(int dir){
	if(dir == NORTH)
		return SOUTH;
	else if(dir == SOUTH)
		return NORTH;
	else if(dir == EAST)
		return WEST;
	else if(dir == WEST)
		return EAST;
	else
		return -1;	
}

int cleanMap(){
	// 1. 현재 위치를 청소한다.
	map[robotPos.r][robotPos.c] = 2;

	// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	int leftSide;
	robotPos.rotateCnt++;
	leftSide = whatIsLeftSide(robotPos.dir);
	// a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
	bool cleanSpotExist = false;
	//for(int i = 1 ; )
	
	
	if(robotPos.rotateCnt <= 4
		// && robotPos.r + dirArr[leftSide].first >= 0
		// && robotPos.r + dirArr[leftSide].first < N
		// && robotPos.c + dirArr[leftSide].second >= 0
		// && robotPos.c + dirArr[leftSide].second < M
		&& map[robotPos.r + dirArr[leftSide].first][robotPos.c + dirArr[leftSide].second] == 0)
	{
		robotPos.r += dirArr[leftSide].first;
		robotPos.c += dirArr[leftSide].second;
		robotPos.dir = leftSide;
		robotPos.rotateCnt = 0;
		return 1;
	}
	
	// b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	else if(robotPos.rotateCnt <= 4){
		robotPos.dir = leftSide;
		return 2;
	}

	// c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
	int reverseSide = whatIsReverseSide(robotPos.dir);
	if(// robotPos.r + dirArr[reverseSide].first >= 0
		// && robotPos.r + dirArr[reverseSide].first < N
		// && robotPos.r + dirArr[reverseSide].second >= 0
		// && robotPos.r + dirArr[reverseSide].second < 0
		map[robotPos.r + dirArr[reverseSide].first][robotPos.c + dirArr[reverseSide].second] != 1){
		robotPos.r += dirArr[reverseSide].first;
		robotPos.c += dirArr[reverseSide].second;
		robotPos.rotateCnt = 0;
		return 3;
	}
	// d. 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
	else{
		return 4;
	}
}

