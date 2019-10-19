#define DEBUG 0
#define LOG(string) cout << string

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

void game();
void moveBlock(int, int, int);

int originMap[20][20];
int map[20][20];
bool alreadySum[20][20];
int N;
int maxValue = -1;
vector<int> dirVector;

pair<int, int> direction[4] = {
	make_pair(0, 1), // EAST
	make_pair(0, -1), // WEST
	make_pair(1, 0), // SOUTH
	make_pair(-1, 0) // NORTH
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> originMap[i][j];
		}
	}

	game();
	cout << maxValue;

    return 0;
}

void game(){
	// escape condition
	if(dirVector.size() >= 5){
		
		// 지도 복사
		for(int i = 0 ; i < N ; i++){
			memcpy(map[i], originMap[i], sizeof(int) *  N);
		}

		for(int i = 0 ; i < dirVector.size() ; i++){
			// 매 번 합쳤는지를 나타내는 배열 초기화
			for(int t = 0 ; t < N ; t++){
				memset(alreadySum[t], 0, sizeof(bool) * N);
			}
			
			if(dirVector[i] == NORTH){
				// 북쪽 이동
				for(int a = 1 ; a < N ; a++){
					for(int b = 0 ; b < N ; b++){
						moveBlock(a, b, NORTH);
					}
				}
			}

			else if(dirVector[i] == WEST){
				// 서쪽 이동
				for(int a = 0 ; a < N ; a++){
					for(int b = 1 ; b < N ; b++){
						moveBlock(a, b, WEST);
					}
				}
			}

			else if(dirVector[i] == SOUTH){
				// 남쪽 이동
				for(int a = N-2 ; a >= 0 ; a--){
					for(int b = 0 ; b < N ; b++){
						moveBlock(a, b, SOUTH);
					}
				}
			}

			else if(dirVector[i] == EAST){
				// 동쪽 이동
				for(int a = 0 ; a < N ; a++){
					for(int b = N - 2 ; b >= 0 ; b--){
						moveBlock(a, b, EAST);
					}
				}
			}
		}
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if(map[i][j] > maxValue){
					maxValue = map[i][j];
				}
			}
		}

		return;
	}

	for(int i = 0 ; i < 4 ; i++){
		dirVector.push_back(i);
		game();
		dirVector.pop_back();
	}

}

void moveBlock(int curRow, int curCol, int dir){
	while(1){
		if(curRow + direction[dir].first < 0 
		|| curRow + direction[dir].first >= N
		|| curCol + direction[dir].second < 0
		|| curCol + direction[dir].second >= N){
			break;
		}

		else if(map[curRow + direction[dir].first][curCol + direction[dir].second] != 0){
			// 값이 같으면 합침.
			if(map[curRow + direction[dir].first][curCol + direction[dir].second] == map[curRow][curCol]
				&& alreadySum[curRow + direction[dir].first][curCol + direction[dir].second] == false)
			{
				alreadySum[curRow + direction[dir].first][curCol + direction[dir].second] = true;
				map[curRow + direction[dir].first][curCol + direction[dir].second] *= 2; // 값 합침.
				map[curRow][curCol] = 0;
			}

			break;
		}
		int tempValue = map[curRow][curCol];
		map[curRow][curCol] = 0;
		curRow += direction[dir].first;
		curCol += direction[dir].second;
		map[curRow][curCol] = tempValue;
	}

	return;
}
