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

    // Algorithm
    int n;
	cin >> n;

	int answer = 0;
	for(int i = 1 ; i < n ; i++){		
		int sum = 0;
		sum += i;
		int temp = i;
		while(1){
			if(temp == 0)
				break;
			else{
				sum += (temp % 10);
				temp /= 10;
			}
		}

		if(sum == n){
			answer = i;
			break;
		}
			
	}

	cout << answer;
    
    return 0;
}
