#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int N, M, T;
vector<deque<int> > map;
int visit[51][50];
vector<pair<int, int> > candidate;

void rotateCW(int, int);  	// 시계방향 회전
void rotateCCW(int, int); 	// 반시계방향 회전
void visitInit();			// 방문 초기화
void removeSame(int, int);  // 같은 값 삭제
void correction();          // 값 보정

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// 원판 읽기.
	cin >> N >> M >> T;
	
	map.push_back(deque<int>()); // 0번 index 사용하지 않음.
	for(int i = 1 ; i <= N ; i++){
		map.push_back(deque<int>());
		for(int j = 1 ; j <= M ; j++){
			int temp;
			cin >> temp;
			map[i].push_back(temp);
		}
	}

	for(int i = 0 ; i < T ; i++){
		int x, d, k;
		cin >> x >> d >> k;
		// 회전
		for(int a = 1 ; a <= N ; a++){
			if(a % x == 0){
				if(d == 0)
					rotateCW(a, k);
				else
					rotateCCW(a, k);
			}
		}
		
		
		// 같은 숫자 지우기
		bool isRemove = false;
		for(int a = 1 ; a <= N ; a++){
			for(int b = 0 ; b < M ; b++){
				visitInit();
				removeSame(a, b);	
				if(candidate.size() > 1){
					isRemove = true;
					for(int c = 0 ; c < candidate.size() ; c++){
						map[candidate[c].first][candidate[c].second] = 0;
					}
				}
			}
		}
	
		// 보정
		if(isRemove == false){
			correction();
		}
		
	}
	
	// 최종 합계
	int sum = 0;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 0 ; j < M ; j++){
			sum += map[i][j];
		}
	}

	cout << sum;

    return 0;
}

void rotateCW(int row, int n){
	for(int i = 0 ; i < n ; i++){
		int temp = map[row][M-1];
		map[row].pop_back();
		map[row].push_front(temp);
	}
}

void rotateCCW(int row, int n){
	for(int i = 0 ; i < n ; i++){
		int temp = map[row][0];
		map[row].pop_front();
		map[row].push_back(temp);
	}
}

void visitInit(){
	candidate.clear();

	for(int i = 1 ; i <= N ; i++){
		memset(visit[i], 0, sizeof(int) * M);
	}
}

void removeSame(int r, int c){
	visit[r][c] = 1;
	candidate.push_back(make_pair(r, c));
	int curVal = map[r][c];
	
	if(curVal == 0){
		return;
	}

	if(r+1 <= N && map[r+1][c] == curVal && visit[r+1][c] == 0){
		removeSame(r+1, c);
	}
	
	if(r-1 >= 1 && map[r-1][c] == curVal && visit[r-1][c] == 0){
		removeSame(r-1, c);
	}

	if(c+1 < M && map[r][c+1] == curVal && visit[r][c+1] == 0){
		removeSame(r, c+1);
	}
	else if(c+1 == M && map[r][0] == curVal && visit[r][0] == 0){
		removeSame(r, 0);
	}

	if(c-1 >= 0 && map[r][c-1] == curVal && visit[r][c-1] == 0){
		removeSame(r, c-1);
	}
	else if(c == 0 && map[r][M-1] == curVal && visit[r][M-1] == 0){
		removeSame(r, M-1);
	}
}

void correction(){
	int sum = 0;
	int cnt = 0;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i][j] > 0){
				cnt++;
				sum += map[i][j];
			}
		}
	}

	if(cnt == 0)
		return;

	double avg = (double)sum / cnt;

	for(int i = 1 ; i <= N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(map[i][j] == 0)
				continue;

			if(map[i][j] > avg){
				map[i][j] -= 1;
			}
			else if(map[i][j] < avg){
				map[i][j] += 1;
			}
		}
	} 
}