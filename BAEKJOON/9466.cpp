#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> pick;
vector<int> group;
vector<int> depth;
vector<bool> visit;

int dfs(int, int, const int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	cin >> test_case;
	while(test_case--){
		cin >> n;

		pick.assign(n+1, 0);
		group.assign(n+1, 0);
		depth.assign(n+1, 0);
		visit.assign(n+1, false);
		for(int i = 1 ; i <= n; i++){
			cin >> pick[i];
		}

		int answer = n;
		int groupId = 0;
		for(int i = 1 ; i <= n ; i++){
			if(!visit[i]) answer -= dfs(i, 0, groupId++);
		}

		cout << answer << "\n";
	}

    return 0;
}

int dfs(int here, int curDepth, const int groupId){
	depth[here] = curDepth;
	group[here] = groupId;
	visit[here] = true;
	int next = pick[here];
	
	if(!visit[next]) return dfs(next, curDepth + 1, groupId);
	else if(groupId == group[next]) return curDepth - depth[next] + 1;
	else return 0;
}