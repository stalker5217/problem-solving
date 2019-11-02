#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> dir[8] = {
	make_pair(-1, -1),
	make_pair(-1, 0),
	make_pair(-1, 1),
	make_pair(0, -1),
	make_pair(0, 1),
	make_pair(1, -1),
	make_pair(1, 0),
	make_pair(1, 1),
};

int map[50][50];
int rowSize, colSize;

bool isIsland(int, int);
void checkNear(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
		cin >> colSize >> rowSize;
		if(rowSize == 0 && colSize == 0){
			break;
		}

		for(int i = 0 ; i < rowSize ; i++){
			for(int j = 0 ; j < colSize ; j++){
				cin >> map[i][j];
			}
		}

		int cnt = 0;
		for(int i = 0 ; i < rowSize ; i++){
			for(int j = 0 ; j < colSize ; j++){
				if(isIsland(i, j)){
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
    
    return 0;
}

bool isIsland(int row, int col){
	bool result = false;
	
	if(map[row][col] == 1){
		checkNear(row, col);
		result = true;
	}

	return result;
}

void checkNear(int row, int col){
	map[row][col] = 2;

	for(int i = 0 ; i < 8 ; i++){
		if(row + dir[i].first >= 0
			&& row + dir[i].first < rowSize
			&& col + dir[i].second >= 0
			&& col + dir[i].second < colSize
			&& map[row + dir[i].first][col + dir[i].second] == 1)
		{
			checkNear(row + dir[i].first, col + dir[i].second);
		}
	}
}
