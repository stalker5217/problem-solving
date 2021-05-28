#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<bool> isPrime(n + 1, true);
	for(int i = 2 ; i * i <= n ; i++){
		if(isPrime[i])
			for(int j = i * i ; j <= n ; j += i) 
				isPrime[j] = false;
	}

	vector<int> primes;
	for(int i = 2 ; i <= n ; i++)
		if(isPrime[i])
			primes.push_back(i);
	
	int start = 0, end = 0;
	int sum = 0, cnt = 0;
	while(true){
		if(sum >= n) sum -= primes[start++];
		else if(primes.size() == end) break;
		else sum += primes[end++];

		if(sum == n) cnt++;
	}

	cout << cnt;
	
    return 0;
}
