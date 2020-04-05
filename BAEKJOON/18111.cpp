#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int map[500][500];

    int row, col, blockCnt;
	cin >> row >> col >> blockCnt;

	int minHeight = 257;
	int maxHeight = 0;
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			cin >> map[i][j];

			if(map[i][j] > maxHeight) maxHeight = map[i][j];
			if(map[i][j] < minHeight) minHeight = map[i][j];
	
			blockCnt += map[i][j];
		}
	}

	long long minTime = 999999999999999L;
	int minTimeHeight;
	for(int height = minHeight ; height <= maxHeight ; height++){
		int time = 0;
		if(row * col * height <= blockCnt){
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					if(map[i][j] >= height){
						time += (map[i][j] - height) * 2;
					}
					else{
						time += (height - map[i][j]);
					}
				}
			}

			if(minTime >= time){
				minTime = time;
				minTimeHeight = height;
			}
		}
	}
	cout << minTime << " " << minTimeHeight;

    return 0;
}
