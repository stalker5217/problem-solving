#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <memory.h>

using namespace std;

int map[50][50];
int newDust[50][50];
int R, C, T;
vector<pair<int, int>> location;
pair<int, int> cleanser1;
pair<int, int> cleanser2;

void findLocation();
void diffusion();
void cleanAir();
void printMap();

int main(){
	cin >> R >> C >> T;

	bool set1 = false;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cin >> map[i][j];

			if(map[i][j] == -1){
				if(set1 == false){
					cleanser1.first = i;
					cleanser1.second = j;
					set1 = true;
				}

				else{
					cleanser2.first = i;
					cleanser2.second = j;
				}
			}
		}
	}
	
	for(int i = 0 ; i < T ; i++){
		findLocation();
		diffusion();
		cleanAir();
		//printMap();
	}
	
	// 최종 결과.
	int remainDust = 0;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			remainDust += map[i][j];
		}
	}
	remainDust += 2; // 공기청정기 -2 값 더해주기.

	cout << remainDust << "\n";

	return 0;
}

// 한 타임에 확산할 좌표 값 확인.
void findLocation(){
	location.clear();
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if(map[i][j] > 0){
				location.push_back(make_pair(i, j));
			} 
		}
	}
}

// 미세 먼지 확산
void diffusion(){
	// 확산된 미세먼지 맵 초기화
	for(int i = 0 ; i < R ; i++){
		memset(newDust[i], 0 , sizeof(int) * C);
	}

	// 경계 값 체크, 공기청정기 체크
	for(int i = 0 ; i < location.size() ; i++){
		int y, x;
		y = location[i].first;
		x = location[i].second;

		int diffCnt = 0;
		// 왼쪽 방향 확산.
		if(x - 1 >= 0 && map[y][x-1] != -1){
			newDust[y][x-1] += map[y][x] / 5;
			diffCnt++;
		}

		// 오른쪽 방향 확산
		if(x + 1 < C && map[y][x+1] != -1){
			newDust[y][x+1] += map[y][x] / 5;
			diffCnt++;
		}

		// 위쪽 방향 확산
		if(y - 1 >= 0 && map[y-1][x] != -1){
			newDust[y-1][x] += map[y][x] / 5;
			diffCnt++;
		}

		// 아래쪽 방향 확산
		if(y + 1 < R && map[y+1][x] != -1){
			newDust[y+1][x] += map[y][x] / 5;
			diffCnt++;
		}
		map[y][x] -= (map[y][x] / 5) * diffCnt;
	}

	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			map[i][j] += newDust[i][j];
		}
	}
}

// 공기청정기 가동
void cleanAir(){
	// 위쪽 공기청정기
	for(int i = cleanser1.first ; i > 0 ; i--){
		map[i][0] = map[i - 1][0];
	}
	for(int i = 0 ; i < C - 1 ; i++){
		map[0][i] = map[0][i+1];
	}
	for(int i = 0 ; i < cleanser1.first ; i++){
		map[i][C-1] = map[i+1][C-1];
	}
	for(int i = C-1 ; i > 1 ; i--){
		map[cleanser1.first][i] = map[cleanser1.first][i-1];
	}
	map[cleanser1.first][cleanser1.second] = -1;
	map[cleanser1.first][cleanser1.second + 1] = 0;
	
	// 아래쪽 공기청정기
	for(int i = cleanser2.first + 1 ; i < R - 1 ; i++){
		map[i][0] = map[i+1][0];
	}
	for(int i = 0 ; i < C - 1 ; i++){
		map[R-1][i] = map[R-1][i+1];
	}
	for(int i = R - 1 ; i > cleanser2.first ; i--){
		map[i][C - 1] = map[i - 1][C - 1];
	}
	for(int i = C - 1 ; i > 1 ; i--){
		map[cleanser2.first][i] = map[cleanser2.first][i-1];
	}
	
	map[cleanser2.first][cleanser2.second] = -1;
	map[cleanser2.first][cleanser2.second + 1] = 0;
}

// 디버깅용 현재 map 출력
void printMap(){
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}