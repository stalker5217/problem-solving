#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int origin[10][10];
int arr[10][10];
int answer = 0;
pair<int, int> dir[4] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

void toggle(int row, int col) {
	arr[row][col] ^= 1;
	for(int i = 0 ; i < 4 ; i++) {
		int nextRow = row + dir[i].first;
		int nextCol = col + dir[i].second;

		if(nextRow >= 0 && nextRow < 10 && nextCol >= 0  && nextCol < 10)
			arr[nextRow][nextCol] ^= 1;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			char temp;
			cin >> temp;
			origin[i][j] = temp == '#' ? 0 : 1;
		}
	}

	int answer = (1 << 10);

	// 첫 번째 행의 모든 경우의 수
	for(int step = 0 ; step < (1 << 10) ; step++) {
		memcpy(arr, origin, sizeof(origin));

		int count = 0;
		
		for(int i = 0 ; i < 10 ; i++) {
			if(step & (1 << i)) {
				++count;
				toggle(0, i);
			}
		}

		for(int i = 1 ; i < 10 ; i++) {
			for(int j = 0 ; j < 10 ; j++) {
				if(arr[i-1][j]) {
					++count;
					toggle(i, j);
				}
			}
		}

		bool allOff = true;
		for(int i = 0 ; i < 10 ; i++) {
			if(arr[9][i]) {
				allOff = false;
				break;
			}
		}

		if(allOff) answer = min(answer, count);
	}

	answer = (answer == (1 << 10)) ? -1 : answer;
	cout << answer;
    
    return 0;
}