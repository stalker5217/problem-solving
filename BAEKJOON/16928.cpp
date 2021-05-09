#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ladderCnt, snakeCnt;
	cin >> ladderCnt >> snakeCnt;

	unordered_map<int, int> jump;
	for(int i = 0 ; i < ladderCnt + snakeCnt ; i++){
		int x, y;
		cin >> x >> y;
		jump[x] = y;
	}

	int tryCnt = 0;
	queue<int> position;
	vector<bool> visit(100, false);
	
	visit[1] = true;
	position.push(1);
	
	while(!position.empty()){
		int size = position.size();
		tryCnt++;
		for(int i = 0 ; i < size ; i++){
			int current = position.front();
			position.pop();

			for(int dice = 1 ; dice <= 6 ; dice++){
				int next = dice + current;
				if(next == 100){
					cout << tryCnt;
					return 0;
				}
				else if(next < 100){
					if(jump.find(next) == jump.end() && !visit[next]){
						position.push(next);
						visit[next] = true;
					}
					else{
						int jumpPosition = jump[next];
						if(!visit[jumpPosition]){
							position.push(jumpPosition);
							visit[jumpPosition] = true;
						}
					}
				}
			}
		}
	}
    
    return 0;
}