#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int personCnt, partyCnt;

int adj[51][51];
bool visit[51];

void dfs(int startV);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> personCnt >> partyCnt;
    
	// 진실을 아는 자..
	int trueManCnt;
	cin >> trueManCnt;
	vector<int> trueMan(trueManCnt, 0);
	for(int i = 0 ; i < trueManCnt ; i++){
		cin >> trueMan[i];
	}

	// 파티 정보 초기화
	vector<int> partyInfo[50];
	for(int i = 0 ; i < partyCnt ; i++){
		int num;
		cin >> num;

		for(int j = 0 ; j < num ; j++){
			int personNum;
			cin >> personNum;
			partyInfo[i].push_back(personNum);
		}
	}

	// 만나는 인간 이어주기
	for(int i = 0 ; i < partyCnt ; i++){
		for(int j = 0 ; j < partyInfo[i].size() - 1; j++){
			adj[partyInfo[i][j]][partyInfo[i][j + 1]] = 1;
			adj[partyInfo[i][j + 1]][partyInfo[i][j]] = 1;
		}
	}

	// 진실을 아는 자와 마주치는 놈들 처리
	for(int i = 0 ; i < trueManCnt ; i++){
		if(!visit[trueMan[i]]) dfs(trueMan[i]);
	}

	// 구라쳐도 되는 파티 카운트
	int answer = 0;
	for(int i = 0 ; i < partyCnt ; i++){
		bool canGura = true;
		for(int j = 0 ; j < partyInfo[i].size() ; j++){
			if(visit[partyInfo[i][j]]){
				canGura = false;
				break;
			}
		}

		if(canGura) answer++;
	}

	cout << answer;
	
    return 0;
}

void dfs(int startV){
	visit[startV] = true;

	for(int i = 1 ; i <= personCnt ; i++){
		if(adj[startV][i] > 0 && !visit[i]) dfs(i);
	}
}