#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, targetCnt;
	cin >> n >> targetCnt;

	deque<int> dq;
	for(int i = 1 ; i <= n ; i++){
		dq.push_back(i);
	}

	int cnt = 0; 
	for(int t = 0 ; t < targetCnt ; t++){
		int target;
		cin >> target;
		
		int targetIdx = -1;
		for(int i = 0 ; i < dq.size() ; i++){
			if(dq[i] == target){
				targetIdx = i;
				break;
			}
		}

		if(targetIdx <= dq.size() / 2){
			while(true){
				if(dq.front() == target){
					dq.pop_front();
					break;
				}
				else{
					dq.push_back(dq.front());
					dq.pop_front();
					cnt++;
				}
			}
		}
		else{
			while(true){
				if(dq.front() == target){
					dq.pop_front();
					break;
				}
				else{
					dq.push_front(dq.back());
					dq.pop_back();
					cnt++;
				}
			}
		}
	}

	cout << cnt;
	
    return 0;
}