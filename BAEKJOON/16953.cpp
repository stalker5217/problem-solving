#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <queue>

using namespace std;

void bfs(long long, const long long & goal);
int answer = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long start, goal;
    cin >> start >> goal;

    bfs(start, goal);
    cout << answer;

    return 0;
}

void bfs(long long start, const long long & goal){
    queue<long long> valQueue;
    valQueue.push(start);

    int cnt = 0;
    while(!valQueue.empty()){
        int curSize = valQueue.size();

        for(int i = 0 ; i < curSize ; i++){
            long long curValue = valQueue.front();
            valQueue.pop();

            if(curValue == goal) answer = cnt + 1;
            else{
                if(curValue * 2 <= goal) valQueue.push(curValue * 2);
                if(curValue * 10 + 1 <= goal) valQueue.push(curValue * 10 + 1);
            }
        }

        cnt++;
    }
}