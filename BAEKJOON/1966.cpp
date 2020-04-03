#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;
	for(int t = 0 ; t < test_case ;  t++){
		int n, m; // 전체, target index
		cin >> n >> m;
		queue<pair<int, int> > printWait;
		priority_queue<int> priority;
		for(int i = 0 ; i < n ; i++){
			int temp;
			cin >> temp;
			printWait.push(make_pair(i, temp));
			priority.push(temp);
		}

		int printOrd = 0;
		while(true){
			int maxImportance = priority.top();
			
			// 출력
			if(maxImportance == printWait.front().second){
				printOrd++;
				if(printWait.front().first == m){
					break;
				}
				
				priority.pop();
				printWait.pop();
			}
			// 우선순위가 높은게 있는 경우
			else{
				pair<int, int> temp = printWait.front();
				printWait.pop();
				printWait.push(temp);
			}
		}

		cout << printOrd << "\n";
	}
    
    return 0;
}
