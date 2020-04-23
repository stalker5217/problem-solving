#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int test_case = 1 ; test_case <= t ; ++test_case){
        int cmdCnt;
        cin >> cmdCnt;

        priority_queue<int> maxPQ;
        priority_queue<int, vector<int>, greater<int> > minPQ;
        unordered_map<int, int> existCheck;

        for(int i = 0 ; i < cmdCnt ; i++){
            char cmd;
            cin >> cmd;

            if(cmd == 'I'){
                int num;
                cin >> num;

                maxPQ.push(num);
                minPQ.push(num);
                existCheck[num]++;
            }
            else if(cmd == 'D'){
                int cmdParam;
                cin >> cmdParam;

                if(cmdParam == -1){
                    while(true){
                        if(minPQ.empty()) break;
                        
                        int removeTarget = minPQ.top();
                        minPQ.pop();

                        if(existCheck[removeTarget] > 0){
                            existCheck[removeTarget]--;
                            break;
                        }
                    }    
                }
                else if(cmdParam == 1){
                    while(true){
                        if(maxPQ.empty()) break;
                        
                        int removeTarget = maxPQ.top();
                        maxPQ.pop();

                        if(existCheck[removeTarget] > 0){
                            existCheck[removeTarget]--;
                            break;
                        }
                    }
                }
            }
        }

        int maxResult, minResult;
        bool isEmpty = true;
        while(!maxPQ.empty()){
            int cur = maxPQ.top();
            if(existCheck[cur] > 0){
                isEmpty = false;
                maxResult = cur;
                break;
            }
            else{
                maxPQ.pop();
            }
        }

        while(!minPQ.empty()){
            int cur = minPQ.top();
            if(existCheck[cur] > 0){
                isEmpty = false;
                minResult = cur;
                break;
            }
            else{
                minPQ.pop();
            }
        }
        
        if(isEmpty) cout << "EMPTY\n";
        else cout << maxResult << " " << minResult << "\n";
    }

    return 0;
}
