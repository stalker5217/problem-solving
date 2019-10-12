#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

char wheel[4][10];

void rotate(int, int, int);
void rotateCW(char[]); // Clock Wise 회전
void rotateCCW(char[]); // Counter Clock Wise 회전

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			cin >> wheel[i][j];
		}
	}

	int k;
	cin >> k;
	for(int i = 0 ; i < k ; i++){
		int n, dir;
		cin >> n >> dir;
		rotate(n-1, dir, 0);
	}

	int sum = 0;
	int weight = 1;
	for(int i = 0 ; i < 4 ; i++){
		if(wheel[i]){
			sum += (wheel[i][0] - '0') * weight;
		}
		weight *= 2;
	}

	
	if(DEBUG){
		for(int i = 0 ; i < 4 ; i++){
			for(int j = 0 ; j < 8 ; j++){
				LOG(wheel[i][j]);
				LOG(" ");
			}
			LOG("\n");
		}
	}
	
	cout << sum;

    return 0;
}

/*
회전 함수
n : 바퀴 번호
dir : 1번은 시계 방향 회전, -1은 시계 반대 방향 회전
whereBy : 0번은 최초 시작, 1은 오른쪽으로 부터오는 움직임, 2는 왼쪽으로 부터 오는 움직임
*/
void rotate(int n, int dir, int whereBy){
	
	// 좌측
	if(n > 0 && wheel[n][6] != wheel[n-1][2] && whereBy != 2){
		int tempDir = dir * -1;
		rotate(n-1, tempDir, 1);
	}

	// 우측
	if(n < 3 && wheel[n][2] != wheel[n+1][6] && whereBy != 1){
		int tempDir = dir * -1;
		rotate(n+1, -dir, 2);
	}

	if(dir == 1){
		rotateCW(wheel[n]);
	}
	else if(dir == -1){
		rotateCCW(wheel[n]);
	}
}

void rotateCW(char arr[]){
	char temp = arr[7];
	for(int i = 6 ; i >= 0 ; i--){
		arr[i+1] = arr[i];
	}
	arr[0] = temp;
}

void rotateCCW(char arr[]){
	char temp = arr[0];
	for(int i = 0 ; i < 7 ; i++){
		arr[i] = arr[i+1];
	}
	arr[7] = temp;
}
