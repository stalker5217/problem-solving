#define DEBUG 0
#define LOG(string) cout << string

#define WHITE 0
#define BLACK 1

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
int arr[50][50];

int checkWhite(int row, int col){
	int rightColor = WHITE;
	int cnt = 0;
	for(int i = row ; i < row + 8 ; i++){
		rightColor = (rightColor == WHITE) ? BLACK : WHITE;
		for(int j = col ; j < col + 8 ; j++){
			if(arr[i][j] != rightColor){
				cnt++;
			}
			rightColor = (rightColor == WHITE) ? BLACK : WHITE;
		}
	}
	return cnt;
}

int checkBlack(int row, int col){
	int rightColor = BLACK;
	int cnt = 0;
	for(int i = row ; i < row + 8 ; i++){
		rightColor = (rightColor == WHITE) ? BLACK : WHITE;
		for(int j = col ; j < col + 8 ; j++){
			if(arr[i][j] != rightColor){
				cnt++;
			}
			rightColor = (rightColor == WHITE) ? BLACK : WHITE;
		}
	}
	return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			char temp;
			cin >> temp;
			if(temp == 'W'){
				arr[i][j] = WHITE;
			}
			else{
				arr[i][j] = BLACK;
			}
		}	
	}

	int min = 64;
	for(int i = 0 ; i <= N - 8 ; i++){
		for(int j = 0 ; j <= M - 8 ; j++){
			int retW, retB;
			retW = checkWhite(i, j);
			retB = checkBlack(i, j);

			int smaller = (retW > retB) ? retB : retW;
			if(min > smaller){
				min = smaller;
			}
		}
	}

	cout << min;
    
    return 0;
}
