#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void combination(int, int);
void pollution(int, int);

int N, M;
int orginMap[8][8];
int map[8][8];
int maxSafe = -1;
vector<pair<int, int>> blankSpot;
vector<pair<int, int>> choiceSpot;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> orginMap[i][j];
			if(orginMap[i][j] == 0){
				blankSpot.push_back(make_pair(i, j));
			}
		}
	}

	combination(0, 3);

	cout << maxSafe;

    return 0;
}

void combination(int offset, int k){
	// escape condition
	if(k == 0){
		// 지도 복사
		for(int i = 0 ; i < N ; i++){
			memcpy(map[i], orginMap[i], sizeof(int) * M); 
		}

		// 현재 선택된 벽 세우기
		for(int i = 0 ; i < choiceSpot.size() ; i++){
			map[choiceSpot[i].first][choiceSpot[i].second] = 1;
		}

		// 바이러스 퍼트리기.
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				if(map[i][j] == 2){
					pollution(i, j);
				}	
			}
		}

		// 안전 지대 검사
		int safeZone = 0;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				if(map[i][j] == 0){
					safeZone++;
				}
			}
		}
		if(maxSafe < safeZone){
			maxSafe = safeZone;
		}
		return;
	}

	for(int i = offset ; i <= blankSpot.size() - k ; i++){
		choiceSpot.push_back(blankSpot[i]);
		combination(i+1, k-1);
		choiceSpot.pop_back();
	}
}

void pollution(int i , int j){
	if(i - 1 >= 0 && map[i-1][j] == 0){
		map[i-1][j] = 3;
		pollution(i-1, j);
	}

	if(j - 1 >= 0 && map[i][j-1] == 0){
		map[i][j-1] = 3;
		pollution(i, j-1);
	}

	if(i + 1 < N && map[i+1][j] == 0){
		map[i+1][j] = 3;
		pollution(i+1, j);
	}

	if(j + 1 < M && map[i][j+1] == 0){
		map[i][j+1] = 3;
		pollution(i, j+1);
	}
}
