#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

void findParent(const int &);

vector<int> connect[100001];
vector<int> parent;
vector<bool> visit;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int first, second;
		cin >> first >> second;
		connect[first].push_back(second);
		connect[second].push_back(first);
	}

	parent.assign(n+1, 0);
	visit.assign(n+1, 0);
	
	findParent(1);

	for(int i = 2 ; i < parent.size() ; i++){
		cout << parent[i] << "\n";
	}

    return 0;
}

void findParent(const int & cur){
	visit[cur] = true;

	for(int i = 0 ; i < connect[cur].size() ; i++){
		int next = connect[cur][i];
		if(!visit[next]){
			parent[next] = cur;
			findParent(next);
		}
	}
}