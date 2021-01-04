#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int singerCnt, pdCnt;
	cin >> singerCnt >> pdCnt;

	vector<vector<int> > adj(singerCnt+1, vector<int>(singerCnt+1, 0));
	vector<int> indegree(singerCnt + 1, 0);

	for(int p = 0 ; p < pdCnt ; p++){
		int orderCnt;
		cin >> orderCnt;
		
		int before = -1;
		int after;
		for(int i = 0 ; i < orderCnt ; i++){
			cin >> after;
			if(before != -1 && adj[before][after] == 0){
				adj[before][after] = 1;
				indegree[after]++;
			}
			before = after;
		}	
	}

	queue<int> q;
	for(int i = 1 ; i <= singerCnt ; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	vector<int> answer;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for(int i = 0 ; i < adj[cur].size() ; i++){
			if(adj[cur][i] == 1){
				if(--indegree[i] == 0){
					q.push(i);
				}
			}
		}
	}

	if(answer.size() < singerCnt){
		cout << "0";
	}
	else{
		for(int singer : answer){
			cout << singer << "\n";
		}
	}
    
    return 0;
}