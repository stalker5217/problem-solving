#define DEBUG 0
#define LOG(string) cout << string

#define INF 10000000000000000L

#include <iostream>
#include <vector>

using namespace std;

int cityCnt, lineCnt;
vector<pair<int, long long> > adj[501];

vector<long long> bellmanFord(int startV);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> cityCnt >> lineCnt;
    while(lineCnt--){
        int startV, destV;
        long long weight;
        cin >> startV >> destV >> weight;

        adj[startV].push_back({destV, weight});
    }
 
    vector<long long> dist = bellmanFord(1);

    if(dist.size() == 0) cout << "-1";
    for(int i = 2 ; i < dist.size() ; i++){
        if(dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
    
    return 0;
}

vector<long long> bellmanFord(int startV){
    vector<long long> upper(cityCnt + 1, INF);
    upper[startV] = 0;
    bool updated;

    for(int iter = 1 ; iter <= cityCnt ; iter++){
        updated = false;

        for(int here = 1 ; here <= cityCnt ; here++){
            if(upper[here] == INF) continue;
            
            for(int i = 0 ; i < adj[here].size() ; i++){
                long long there = adj[here][i].first;
                long long cost = adj[here][i].second;

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