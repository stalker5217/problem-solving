#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void grouping(int, int);

int mapSize;
int map[25][25];
bool check[25][25];
int curCnt;
vector<int> groupCnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    cin >> mapSize;
	for(int i = 0 ; i < mapSize ; i++){
		for(int j = 0 ; j < mapSize ; j++){
			char tempChar;
			cin >> tempChar;
			map[i][j] = tempChar - '0';
			check[i][j] = false;
		}
	}


	for(int i = 0 ; i < mapSize ; i++){
		for(int j = 0 ; j < mapSize ; j++){
			if(map[i][j] == 1 && check[i][j] == false){
				curCnt = 0;
				grouping(i, j);
				groupCnt.push_back(curCnt);
			} 
		}
	}

	sort(groupCnt.begin(), groupCnt.end());

	cout << groupCnt.size() << "\n";
	for(int i = 0 ; i < groupCnt.size() ; i++){
		cout << groupCnt[i] << "\n";
	}

    return 0;
}

void grouping(int i, int j){
	check[i][j] = true;
	curCnt++;

	if(i+1 < mapSize && map[i+1][j] == 1 && check[i+1][j] == false){
		grouping(i+1, j);
	}

	if(j+1 < mapSize && map[i][j+1] == 1 && check[i][j+1] == false){
		grouping(i, j+1);
	}

	if(i - 1 >= 0 && map[i - 1][j] == 1 && check[i - 1][j] == false){
		grouping(i-1, j);
	}

	if(j - 1 >= 0 && map[i][j - 1] == 1 && check[i][j - 1] == false){
		grouping(i, j-1);
	}
}
