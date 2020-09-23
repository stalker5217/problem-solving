#define DEBUG 0
#define LOG(string) cout << string

#define INF 123456789

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
    vector<vector<int> > adj(n+1, vector<int>(n+1, INF));

	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
	}

	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int answer = 0;
	for(int i = 1 ; i <= n ; i++){
		bool allConnect = true;
		for(int j = 1 ; j <= n ; j++){
			if(i == j) continue;
			if(adj[i][j] == INF && adj[j][i] == INF){
				allConnect = false;
				break;
			}
		}

		if(allConnect) answer++;
	}

	cout << answer;
    
    return 0;
}
