#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int planeCnt;
	cin >> planeCnt;

	const long long mod = 1'000'000'007;
	long long answer = 0;
	while(planeCnt--){
		long long n, s;
		cin >> n >> s;

		int g = gcd(n, s);
		n /= g;
		s /= g;

		long long inverse = 1, pow = mod - 2;
		while(pow > 0){
			if(pow & 1) inverse = (inverse * n) % mod;
			n = (n * n) % mod;
			pow >>= 1;
		}

		answer += (s * inverse) % mod;
		answer %= mod;
	}

	cout << answer;
	    
    return 0;
}