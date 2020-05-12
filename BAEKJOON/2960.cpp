#define DEBUG 0
#define LOG(string) cout << string

#define MAX 1000

#include <iostream>
#include <cstring>
#include <cmath>

int n, k;
int eratosthenes();

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> k;
	cout << eratosthenes();
    
    return 0;
}


int eratosthenes(){
	bool isPrime[MAX+1];
	memset(isPrime, 1, sizeof(isPrime));

	int cnt = 0;
	for(int i = 2 ; i <= n ; i++){
		if(isPrime[i]){
			isPrime[i] = 0;
			cnt++;
			if(cnt == k) return i;
			/**
			 *	2 * i 에서 시작하는 것이 아니라 i * i에서 시작한다.
			 *  만약, i를 3번 째 소수인 5라고 가정하면
			 *  2 * 5, 3 * 5 같은 수는 이미 앞에서 지워졌기 때문이다.
			 */
			for(int j = i * i ; j <= n ; j += i){
				if(isPrime[j] == 1){
					isPrime[j] = 0;
					cnt++;
					if(cnt == k) return j;
				}
			}
		}
	}

	return -1;
}
