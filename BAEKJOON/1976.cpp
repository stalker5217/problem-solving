#define DEBUG 0
#define LOG(string) cout << string
#define MERGE 0

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{

private:
	vector<int> parent;
	vector<int> rank;

public:
	DisjointSet(int n)
	: parent(n+1), rank(n+1, 1)
	{
		for(int i = 1 ; i <= n ; i++){
			parent[i] = i;
		}
	}

	int find(int u){
		if(u == parent[u]) return u;
		else return parent[u] = find(parent[u]);
	}

	void merge(int u, int v){
		u = find(u);
		v = find(v);

		if(u == v) return;

		if(rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]++;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	DisjointSet sets(n);

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			int isConnect;
			cin >> isConnect;
			
			if(isConnect){
				sets.merge(i, j);
			}
		}
	}

	bool sameRoot = true;
	int city;
	cin >> city;
	int root = sets.find(city);
	for(int i = 1 ; i < m ; i++){
		cin >> city;
		if(root != sets.find(city)){
			sameRoot = false;
			break;
		}
	}

	if(sameRoot) cout << "YES";
	else cout << "NO";

    return 0;
}