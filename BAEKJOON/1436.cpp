#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;
	int answer = 0;
	for(int i = 1 ; true ; i++){
		int num = i;
		int six = 0;
		// 666 있는지 검사
		while(true){
			if(num % 10 == 6){
				six++;
				if(six == 3){
					cnt++;
					if(cnt == n){
						answer = i;
						break;
					}
				}
			}
			else{
				six = 0;
			}
			
			num /= 10;
			if(num == 0){
				break;
			}
		}

		if(answer > 0){
			break;
		}
	}

	cout << answer;
    
    return 0;
}
