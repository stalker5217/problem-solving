#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int N, L;

bool checkRoad(int[]);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int map[100][100];
	int tempArr[100];

	cin >> N >> L;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
		}
	}

	int roadCnt = 0;
	for(int i = 0 ; i < N ; i++){
		// 가로 방향 검사
		bool result;
		result = checkRoad(map[i]);
		if(result){
			//LOG("garo ");
			//LOG(i);
			//LOG("\n");
			roadCnt++;
		}
		
		// 세로 방향 검사
		for(int j = 0 ; j < N ; j++){
			tempArr[j] = map[j][i];
		}
		checkRoad(tempArr);
		result = checkRoad(tempArr);
		if(result){
			//LOG("sero ");
			//LOG(i);
			//LOG("\n");
			roadCnt++;
		}
	}

	cout << roadCnt;

    return 0;
}

bool checkRoad(int road[]){
	bool isRoad = true;
	bool alreadExist[100] = {false, };
	int curIndex = 0;

	while(1){
		// 끝까지가면 탈출 
		if(curIndex == N-1){
			break;
		}

		// 인접 칸과 같은 경우 지나감
		if(road[curIndex] == road[curIndex + 1]){
			curIndex++;
			continue;
		}

		// 인접 칸과 두 칸 차이나는 경우 실패
		else if(abs(road[curIndex] - road[curIndex + 1]) > 1){
			isRoad = false;
			break;
		}

		// 인접 칸이 한 칸 더 높은 경우
		else if(road[curIndex + 1] - road[curIndex] == 1){
			// 왼쪽 끝인 경우 세울 수 없음
			if(curIndex < L - 1){
				isRoad = false;
				break;
			}

			bool isAllSame = true;
			int height = road[curIndex];
			for(int k = 0; k < L ; k++ ){
				if(height != road[curIndex - k] || alreadExist[curIndex - k] == true){
					isAllSame = false;
				}
			}

			if(isAllSame){
				for(int k = 0; k < L ; k++ ){
					alreadExist[curIndex - k] = true;
					break;
				}
			}
			else{
				isRoad = false;
				break;
			}
			curIndex++;
		}

		// 인접 칸이 한 칸 더 낮은 경우
		else if(road[curIndex + 1] - road[curIndex] == -1){
			// 오른쪽 끝인 경우 세울 수 없음
			if(curIndex >= N - L){
				isRoad = false;
				break;
			}

			bool isAllSame = true;
			int height = road[curIndex] - 1;
			for(int k = 1 ; k <= L ; k++ ){
				if(height != road[curIndex + k]){
					isAllSame = false;
					break;
				}
			}

			if(isAllSame){
				for(int k = 1; k <= L ; k++ ){
					alreadExist[curIndex + k] = true;
				}
			}
			else{
				isRoad = false;
				break;
			}
			curIndex += L;
		}
	}

	return isRoad;
}
