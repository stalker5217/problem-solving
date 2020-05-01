#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int gcd(ll a, ll b);
ll plusInverse(ll n, ll a);
ll multipleInverse(ll n, ll a);
ll expand_gcd(ll a, ll b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a;
	cin >> n >> a;

	ll pi = plusInverse(n, a);
	ll mi = multipleInverse(n, a);

	cout << pi << " " << mi << endl;

    return 0;
}

int gcd(ll a, ll b){
	if(a < b) swap(a, b);
	if(b == 0) return a;
	else return gcd(b, a % b);
}

ll plusInverse(ll n, ll a){
	return n - a;
}

ll multipleInverse(ll n, ll a){
	// Modulo Inverse는 서로소 일 때만 존재함
	if(gcd(a, n) != 1) return -1;
	else return expand_gcd(a, n);	
}

ll expand_gcd(ll a, ll b){
	vector<ll> r = {a, b};
	vector<ll> s = {1, 0};
	vector<ll> t = {0, 1};
	vector<ll> q = {0, 0}; // dummy

	while(1){
		if(r[r.size() - 1] == 0){
			break;
		}

		// r1 = r_{i-1}
		ll r1 = r[r.size() - 1];
		ll r2 = r[r.size() - 2];
		r.push_back(r2 % r1);

		q.push_back(r2 / r1);
        
		ll s1 = s[s.size() - 1];
		ll s2 = s[s.size() - 2];
        
		ll t1 = t[t.size() - 1];
        ll t2 = t[t.size() - 2];
        
        ll q1 = q[q.size() - 1];
        s.push_back(s2 - s1 * q1);
        t.push_back(t2 - t1 * q1);
	}


	//cout << a << " * " << s[s.size() - 2] << " + " << b << " * " << t[t.size() - 2] << " = " << a*s[s.size() - 2] + b*t[t.size() - 2] << endl;

	return (s[s.size() - 2] > 0) ? s[s.size() - 2] : s[s.size() - 2] + b;
}


