#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

typedef long long ll;

ll getAnswer(ll, ll, ll);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c;
	cin >> a >> b >> c;

	cout << getAnswer(a, b, c);
    
    return 0;
}

ll getAnswer(ll a, ll b, ll c){
	if(b == 1) {
		return a % c;
	}
	else if(b % 2 == 0){
		ll tmp = getAnswer(a, b/2, c);
		return (tmp * tmp) % c;
	}
	else if(b % 2 == 1){
		ll tmp = getAnswer(a, b - 1, c);
		return (tmp * a) % c;
	}
	
	// remove warning
	return -1;
}