#define MAX_N 1000
#define MAX_M 1000

#include <iostream>
#include <vector>

using namespace std;

// Group A, Group B 정점의 개수
int n, m, k;

// A_i와 B_i의 연결 여부
vector<int> adj[MAX_N];

// 각 정점에 매칭된 상대 정점 번호 저장
vector<int> aMatch, bMatch;

// dfs 방문 여부
vector<bool> visited;

bool dfs(int a);
int bipartiteMatch();

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 0 ; i < n ; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0 ; j < cnt ; j++){
			int target;
			cin >> target;
			adj[i].push_back(target-1);
		}
	}

	int size = bipartiteMatch();
	cout << size;

	return 0;
}

bool dfs(int a){
	if(visited[a]) return false;

	visited[a] = true;
	for(int b = 0 ; b < adj[a].size() ; b++){
		// b가 이미 매칭되어 있으면 bMatch[b]에서 부터 시작해 증가 경로를 찾음
		int target = adj[a][b];
		if(bMatch[target] == -1 || dfs(bMatch[target])){
			// 증가 경로 발견
			aMatch[a] = target;
			bMatch[target] = a;

			return true;
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
		if(dfs(start)) size++;
	}

	
	while(true){
		bool isUpdated = false;
		for(int start = 0 ; start < n ; start++){	
			visited = vector<bool>(n, false);
			if(k > 0 && dfs(start)) {
				size++; 
				isUpdated = true;
				break;
			}
		}
		if(!isUpdated || --k <= 0) break;
	}

	return size;
}