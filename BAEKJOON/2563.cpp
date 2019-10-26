#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void drawRectangle(int[100][100], int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int map[100][100];
	int cnt;
	cin >> cnt;

	for(int i = 0 ; i < 100 ; i++){
		memset(map[i], 0, sizeof(int) * 100);
	}

	for(int i = 0 ; i < cnt ; i++){
		int startX, startY;
		cin >> startX >> startY;
		drawRectangle(map, startX, startY);
	}

	int result = 0;
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			if(DEBUG) LOG(map[i][j]);
			if(DEBUG) LOG(" ");
			if(map[i][j] == 1){
				result++;
			}
		}
		if(DEBUG) LOG("\n");
	}

	cout << result;
    
    return 0;
}

void drawRectangle(int map[100][100], int startX, int startY){
	for(int i = startX ; i < startX + 10 ; i++){
		for(int j = startY ; j < startY + 10 ; j++){
			map[i][j] = 1;
		}
	}
}
