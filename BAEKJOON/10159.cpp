#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n+1, vector<int>(n+1));
	for(int i = 0 ; i < m ; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = -1;
	}

	for(int k = 1 ; k <= n ; k++) {
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= n ; j++) {
				if(adj[i][k] != 0 && adj[i][k] == adj[k][j]) {
					adj[i][j] = adj[i][k];
				}
			}
		}
	}

	for(int i = 1 ; i <= n ; i++) {
		int count = 0;
		for(int j = 1 ; j <= n ; j++) {
			if(adj[i][j] == 0) count++;
		}

		// 자기 자신 제외
		cout << count - 1 << "\n";
	}


    return 0;
}