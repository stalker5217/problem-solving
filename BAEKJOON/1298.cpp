#define MAX_N 100
#define MAX_M 100

#include <iostream>
#include <vector>

using namespace std;

// Group A, Group B 정점의 개수
int n, m;

// A_i와 B_i의 연결 여부
bool adj[MAX_N][MAX_M];

// 각 정점에 매칭된 상대 정점 번호 저장
vector<int> aMatch, bMatch;

// dfs 방문 여부
vector<bool> visited;

bool dfs(int a);
int bipartiteMatch();

int main(){
	cin >> n;
	m = n;

	int mineCnt;
	cin >> mineCnt;
	for(int i = 0 ; i < mineCnt ; i++){
		int a, b;
		cin >> a >> b;
		adj[a-1][b-1] = true;
	}

	int matchingCnt = bipartiteMatch();
	cout << matchingCnt << "\n";

	return 0;
}

bool dfs(int a){
	if(visited[a]) return false;

	visited[a] = true;
	for(int b = 0 ; b < m ; b++){
		if(adj[a][b]){
			// b가 이미 매칭되어 있으면 bMatch[b]에서 부터 시작해 증가 경로를 찾음
			if(bMatch[b] == -1 || dfs(bMatch[b])){
				// 증가 경로 발견
				aMatch[a] = b;
				bMatch[b] = a;

				return true;
			}
		}
	}

	return false;
}

int bipartiteMatch(){
	// 초기화
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0;

	for(int start = 0 ; start < n ; start++){
		visited = vector<bool>(n, false);

		// dfs를 사용해 start에서 시작하는 증가 경로를 찾음
		if(dfs(start)) size++;
	}

	return size;
}