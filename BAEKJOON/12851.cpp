#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int moveCnt[100001];
    for(int i = 0 ; i <= 100001 ; i++) moveCnt[i] = 1000000;
    
    int startPos, targetPos;
    cin >> startPos >> targetPos;

    queue<int> posQueue;
    posQueue.push(startPos);
    moveCnt[startPos] = 0;
    int minMoveCnt = 0;
    bool findTarget = false;

    // BFS
    while(!findTarget && !posQueue.empty()){
        int curSize = posQueue.size();
    
        for(int i = 0 ; i < curSize ; i++){
            int pos = posQueue.front();

            if(pos == targetPos) {
                findTarget= true;
                minMoveCnt++;
            }

            if(pos - 1 >= 0 && moveCnt[pos-1] >= moveCnt[pos] + 1) {
                moveCnt[pos-1] = moveCnt[pos] + 1; 
                posQueue.push(pos-1);
            }
            if(pos + 1 <= 100000 && moveCnt[pos+1] >= moveCnt[pos] + 1) {
                moveCnt[pos+1] = moveCnt[pos] + 1;  
                posQueue.push(pos+1);
            }
            if(pos * 2 <= 100000 && moveCnt[pos*2] >= moveCnt[pos] + 1) {
                moveCnt[pos*2] = moveCnt[pos] + 1;  
                posQueue.push(pos*2);
            }
            posQueue.pop();
        }
    }

    cout << moveCnt[targetPos] << "\n";
    cout << minMoveCnt;

    return 0;
}
