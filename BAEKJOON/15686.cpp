#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __pos{
	int r;
	int c;
} pos;

typedef struct __home{
	int r;
	int c;
	int chic_distance;
} home;

int N, M;
int map[50][50];

vector<pos> chicArr;
vector<pos> choiceChicArr;
vector<home> homeArr;

int minChicDistance = 100000000;

void combination(int offset, int k);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				home temp;
				temp.r = i;
				temp.c = j;
				temp.chic_distance = 10000000;

				homeArr.push_back(temp);
			}

			else if(map[i][j] == 2){
				pos temp;
				temp.r = i;
				temp.c = j;

				chicArr.push_back(temp);
			}
		}
	}

	combination(0, M);

	cout << minChicDistance;
    
    return 0;
}

// M개 선택하는 조합
void combination(int offset, int k){
	// escape condition
	if(k == 0){
		// 각 집의 치킨 거리
		int totalDistance = 0;
		for(int i = 0 ; i < homeArr.size() ; i++){
			homeArr[i].chic_distance = 10000000; // 최소 값을 구하기 위한 임시 MAX값으로 초기화
			for(int j = 0 ; j < choiceChicArr.size() ; j++){
				int absR = (homeArr[i].r - choiceChicArr[j].r > 0) ? homeArr[i].r - choiceChicArr[j].r : -(homeArr[i].r - choiceChicArr[j].r);
				int absC = (homeArr[i].c - choiceChicArr[j].c > 0) ? homeArr[i].c - choiceChicArr[j].c : -(homeArr[i].c - choiceChicArr[j].c);
				int distance = absR + absC;

				if(distance < homeArr[i].chic_distance){
					homeArr[i].chic_distance = distance;
				}
			}
			totalDistance += homeArr[i].chic_distance;
		}

		if(minChicDistance > totalDistance){
			minChicDistance = totalDistance;
		}

		return;
	}

	
	for(int i = offset ; i <= chicArr.size() - k ; i++){
		choiceChicArr.push_back(chicArr[i]);
		combination(i + 1, k - 1);
		choiceChicArr.pop_back();
	}
}
