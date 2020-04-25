#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
	cin >> n >> k;

	int cnt = 0;
	int answer = 0;
	for(int i = 1 ; i <= n ; i++){
		if(n % i == 0){
			cnt++;
			if(cnt == k) answer = i;
		}
	}

	cout << answer;
    
    return 0;
}
