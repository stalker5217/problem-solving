#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <vector>

using namespace std;

int vertexCnt, pathCnt, wormholeCnt;
vector<pair<int, int> > adj[501];

vector<int> bellmanFord(int startV);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
    cin >> test_case;
    while(test_case--){
        cin >> vertexCnt >> pathCnt >> wormholeCnt;
        for(int i = 1 ; i <= 500 ; i++) adj[i].clear();

        while(pathCnt--){
            int startV, destV, weight;
            cin >> startV >> destV >> weight;

            adj[startV].push_back({destV, weight});
            adj[destV].push_back({startV, weight});
        }

        while(wormholeCnt--){
            int startV, destV, weight;
            cin >> startV >> destV >> weight;

            adj[startV].push_back({destV, -weight});    
        }

        vector<int> dist = bellmanFord(1);

        if(dist.size() == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}

vector<int> bellmanFord(int startV){
    vector<int> upper(vertexCnt + 1, INF);
    upper[startV] = 0;
    bool updated;

    for(int iter = 1 ; iter <= vertexCnt ; iter++){
        updated = false;

        for(int here = 1 ; here <= vertexCnt ; here++){
            for(int i = 0 ; i < adj[here].size() ; i++){
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                // upper 보정
                if(upper[there] > upper[here] + cost){
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }

        if(!updated) break;
    }

    if(updated) upper.clear();

    return upper;
}