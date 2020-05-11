#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>

using namespace std;

int n;
int edge[100][100];
int visit[100];

void dfs(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
    for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> edge[i][j];
		}
	}

	int result[100][100];
	for(int i = 0 ; i < n ; i++){
		memset(visit, 0, sizeof(int) * n);
		dfs(i);
		for(int v = 0 ; v < n ; v++){
			if(visit[v] == 1) result[i][v] = 1;
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
    
    return 0;
}

void dfs(int start){
	for(int i = 0 ; i < n ; i++){
		if(i != start){
			if(edge[start][i] == 1 && visit[i] == 0){
				visit[i] = 1;
				dfs(i);
			}
		}
	}
}
