#include <iostream>
#include <vector>

#define MAXVAL 4000000
#define MODVAL 1000000007

typedef long long ll;

using namespace std;

ll factorial[MAXVAL + 1];
ll n, k;
void make_factorial();
int fermatInverse(ll n, ll modVal);

int main()
{
	cin >> n >> k;

	if(k == 0 || k == n){
		cout << 1 << endl;
		return 0;
	}

	make_factorial();
	ll answer = (factorial[n] * fermatInverse(factorial[k] * factorial[n-k] % MODVAL, MODVAL)) % MODVAL;
	cout << answer << endl;

	return 0;
}

void make_factorial(){
	factorial[0] = 0;
	factorial[1] = 1;
	for(int i = 2; i <= n ; i++) factorial[i] = (factorial[i-1] * i) % MODVAL;
}

int fermatInverse(ll n, ll modVal){
	ll pow = modVal - 2;
	ll ret = 1;
	while(1){
		if(pow % 2 == 1){
			ret = (ret * n) % modVal;
		}
		n = (n * n) % modVal;
		pow /= 2;

		if(pow == 0) break;
	}

	return ret;
}