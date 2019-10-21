#define DEBUG 0
#define LOG(string) cout << string

#define NONE 0
#define WALL 1
#define VIRUS 2

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
int originMap[50][50];
int map[50][50];
int blankSpot = 0;
int remainSpot = 0;

int minTime = 100000000;
bool isSuccess = false;

vector<pair<int, int> > candidateSpot;
vector<pair<int, int> > virusSpot;
vector<pair<int, int> > virusSpotCopy;

void combination(int offset, int k);
void pollution();

pair<int, int> dir[4] = {
	make_pair(0, 1),
	make_pair(0, -1),
	make_pair(1, 0),
	make_pair(-1, 0)
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> M;
	blankSpot -= M;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> originMap[i][j];
			if(originMap[i][j] == NONE || originMap[i][j] == VIRUS){
				blankSpot++;
			}
			if(originMap[i][j] == VIRUS){
				candidateSpot.push_back(make_pair(i, j));
			}
		}
	}
    
	combination(0, M);

	if(isSuccess)
		cout << minTime;
	else
		cout << -1;
	

    return 0;
}

void combination(int offset, int k){
	if(virusSpot.size() == M){
		
		remainSpot = blankSpot;
		// copy and setting
		for (int i = 0; i < N; i++) {
			memcpy(map[i], originMap[i], sizeof(int) * N);
		}
		for(int i = 0 ; i < virusSpot.size() ; i++){
			map[virusSpot[i].first][virusSpot[i].second] = 3;
		}
	
		int mTime = 0;
		virusSpotCopy.assign(virusSpot.begin(), virusSpot.end());
		while(1){
			if(remainSpot == 0 || virusSpotCopy.empty()){
				break;
			}
			pollution();
			mTime++;
		}

		if(virusSpotCopy.empty() && remainSpot > 0){
			// 다 오염시킬 수 없음.
		}
		else{
			if(minTime > mTime){
				isSuccess = true;
				minTime = mTime;
			}
		}

		return;
	}

	for(int i = offset ; i <= candidateSpot.size() - k ; i++){
		virusSpot.push_back(make_pair(candidateSpot[i].first, candidateSpot[i].second));
		combination(i + 1, k - 1);
		virusSpot.pop_back();
	}
}

void pollution(){
	vector<pair<int, int> > tempSpot;
	tempSpot.assign(virusSpotCopy.begin(), virusSpotCopy.end());
	virusSpotCopy.clear();

	for (int i = 0; i < tempSpot.size(); i++) {
		for (int d = 0; d < 4; d++) {	
			if (tempSpot[i].first + dir[d].first >= 0 &&
				tempSpot[i].first + dir[d].first < N &&
				tempSpot[i].second + dir[d].second >= 0 &&
				tempSpot[i].second + dir[d].second < N &&
				map[tempSpot[i].first + dir[d].first][tempSpot[i].second + dir[d].second] != 1 &&
				map[tempSpot[i].first + dir[d].first][tempSpot[i].second + dir[d].second] != 3
			) 
			{
				remainSpot--;
				map[tempSpot[i].first + dir[d].first][tempSpot[i].second + dir[d].second] = 3;
				virusSpotCopy.push_back(make_pair(tempSpot[i].first + dir[d].first, tempSpot[i].second + dir[d].second));
			}
		}
	}
}