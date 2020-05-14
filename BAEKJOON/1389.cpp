#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int relation[101][101];
int personCnt, relationCnt;

int bfs(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> personCnt >> relationCnt;
    for(int i = 0 ; i < relationCnt ; i++){
        int a, b;
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    int minVal = 987654321;
    int answer;
    for(int i = 1 ; i <= personCnt ; i++){
        int ret = bfs(i);
        if(minVal > ret){
            minVal = ret;
            answer = i;
        }
    }

    cout << answer;
    
    return 0;
}

int bfs(int startPos){
    int cnt = 0;
    
    int visit[101] = {0, };
    visit[startPos] = 1;
    queue<int> q;
    q.push(startPos);
    while(!q.empty()){
        cnt++;
        int qSize = q.size();
        for(int a = 0 ; a < qSize ; a++){
            int cur = q.front();
            q.pop();

            for(int i = 1 ; i <= personCnt ; i++){
                if(relation[cur][i] == 1 && visit[i] == 0){
                    q.push(i);
                    visit[i] = cnt;
                }
            }
        }
    }

    int sum = 0;
    for(int i = 1 ; i <= personCnt ; i++){
        if(i != startPos) sum += visit[i];
    }

    return sum;
}