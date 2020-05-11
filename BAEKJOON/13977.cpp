#include <iostream>

#define MAXVAL 4000000

using namespace std;

typedef long long ll;

ll factorial[MAXVAL + 1];
ll inverse[MAXVAL + 1];
ll n, k;
ll mod = 1e9 + 7;

void init();
ll fermatInverse(ll n);

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	// 선행 작업
	init();

	int t;
	cin >> t;
	for(int test_case = 1 ; test_case <= t ; test_case++){
		cin >> n >> k;

		ll answer = (factorial[n] * (inverse[k])) % mod;
		answer = (answer * (inverse[n-k])) % mod;
		cout << answer << "\n";
	}
	
	return 0;
}

void init(){
	factorial[0] = 0;
	factorial[1] = 1;
	for(int i = 2; i <= MAXVAL ; i++) factorial[i] = (factorial[i-1] * i) % mod;

	inverse[MAXVAL] = fermatInverse(factorial[MAXVAL]);
	for(int i = MAXVAL-1 ; i >= 0 ; i--) inverse[i] = inverse[i+1] * (i+1) % mod;
}


ll fermatInverse(ll n){
	ll pow = mod - 2;
	ll ret = 1;
	while(1){
		if(pow & 1){
			ret = (ret * n) % mod;
		}
		n = (n * n) % mod;
		pow = pow >> 1;

		if(pow == 0) break;
	}

	return ret;
}