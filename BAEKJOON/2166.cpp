#define DEBUG 0
#define LOG(string) cout << string

#define ll long long

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
	return 
		(a.first * b.second + b.first * c.second + c.first * a.second) -
		(a.first * c.second + b.first * a.second + c.first * b.second);
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<ll, ll> > coord;
	for(int i = 0 ; i < n ; i++){
		ll x, y;
		cin >> x >> y;
		coord.push_back({x, y});
	}
    
	double answer = 0;
	for(int i = 1 ; i < n - 1 ; i++){
		answer += ccw(coord[0], coord[i], coord[i+1]);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(answer / 2);
    
    return 0;
}