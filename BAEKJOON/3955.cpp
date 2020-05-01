#define DEBUG 0
#define LOG(string) cout << string
#define MAXVAL 1000000000

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll, ll);
ll extended_gcd(ll, ll);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
	cin >> t;
	for(ll test_case = 1 ; test_case <= t ; test_case++){
		
		ll k, c;
		cin >> k >> c;
		if(gcd(k, c) != 1) cout << "IMPOSSIBLE\n";
		else if(c == 1) {
			if(k+1 <= MAXVAL) cout << k+1 << "\n";
			else cout << "IMPOSSIBLE\n";
		}
		else if(k == 1) cout << 1 << "\n";
		else{
			ll ans = extended_gcd(k, c);
			if(ans <= MAXVAL) cout <<  ans << "\n";
			else cout << "IMPOSSIBLE\n";
		}
	
	}
    
    return 0;
}

// a > b
ll gcd(ll a, ll b){
	if(a < b) swap(a, b);
	return (b > 0) ? gcd(b, a % b) : a;
}

ll extended_gcd(ll a, ll b){
	ll r, q, s, t;
	ll r1 = a, r2 = b;
	ll s1 = 1, s2 = 0;
	ll t1 = 0, t2 = 1;

	// r2 == 0 일 때 종료
	while(r2 > 0){
		q = r1 / r2;

		r = r1 - r2 * q;
		r1 = r2;
		r2 = r;

		s = s1 -s2 * q;
		s1 = s2;
		s2 = s;

		t = t1 - t2 * q;
        t1 = t2;
        t2 = t;
	}

	ll ans = t1;
	while(ans < 0) ans += a;

	return ans;
}