#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int map[20][20];
int N, M;
int commandCnt;

struct __dice{
	int top;
	int west;
	int east;
	int north;
	int south;
	int bottom;
	int x;
	int y;
};

typedef enum __dir{
	EAST = 1,
	WEST,
	NORTH,
	SOUTH
} dirEnum;

struct __dice dice;
vector<dirEnum> command;

bool rollDice(dirEnum dir);
void refreshMap(dirEnum dir);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    cin >> N >> M >> dice.x >> dice.y >> commandCnt;
	dice.top = 0;
	dice.west = 0;
	dice.east = 0;
	dice.north = 0;
	dice.south = 0;
	dice.bottom = 0;

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 0 ; i < commandCnt ; i++){
		int temp;
		cin >> temp;
		if(temp == 1) refreshMap(EAST);
		else if(temp == 2) refreshMap(WEST);
		else if(temp == 3) refreshMap(NORTH);
		else if(temp == 4) refreshMap(SOUTH);
	}

    return 0;
}

bool rollDice(dirEnum dir){
	if(dir == EAST){
		if(dice.y + 1 < M){
			dice.y += 1;
		}
		else{
			//LOG("Out of Bound.\n");
			return false;
		}
		
		int temp = dice.top;
		dice.top = dice.west;
		dice.west = dice.bottom;
		dice.bottom = dice.east;
		dice.east = temp;
	}

	else if(dir == WEST){
		if(dice.y - 1 >= 0){
			dice.y -= 1;
		}
		else{
			//LOG("Out of Bound.\n");
			return false;
		}

		int temp = dice.top;
		dice.top = dice.east;
		dice.east = dice.bottom;
		dice.bottom = dice.west;
		dice.west = temp;
	}

	else if(dir == NORTH){
		if(dice.x - 1 >= 0){
			dice.x -= 1;
		}
		else{
			//LOG("Out of Bound.\n");
			return false;
		}
		
		int temp = dice.top;
		dice.top = dice.south;
		dice.south = dice.bottom;
		dice.bottom = dice.north;
		dice.north = temp;
	}

	else if(dir == SOUTH){
		if(dice.x + 1 < N){
			dice.x += 1;
		}
		else{
			//LOG("Out of Bound.\n");
			return false;
		}
		
		int temp = dice.top;
		dice.top = dice.north;
		dice.north = dice.bottom;
		dice.bottom = dice.south;
		dice.south = temp;
	}

	return true;
}

void refreshMap(dirEnum dir){
	bool result = rollDice(dir);

	if(!result)
		return;

	// 주사위 값 복사
	if(map[dice.x][dice.y] == 0){
		map[dice.x][dice.y] = dice.bottom;
	}
	else{
		dice.bottom = map[dice.x][dice.y];
		map[dice.x][dice.y] = 0;
	}

	cout << dice.top << "\n";
}