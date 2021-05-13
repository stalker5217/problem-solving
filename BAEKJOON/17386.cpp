#define DEBUG 0
#define LOG(string) cout << string
#define ll long long

#include <iostream>
#include <algorithm>

using namespace std;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
	ll result = (a.first * b.second) + (b.first * c.second) + (c.first * a.second) - (a.second * b.first) - (b.second * c.first) - (c.second * a.first);

	if(result > 0) return 1; // 반시계
	else if(result < 0) return -1; // 시계
	else return 0; // 평행
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	pair<ll, ll> a, b, c, d;
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

	int abc = ccw(a, b, c);
	int abd = ccw(a, b, d);
	int cda = ccw(c, d, a);
	int cdb = ccw(c, d, b);

	bool answer;
	// 평형
	if(abc * abd == 0 && cda * cdb == 0){
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);

		answer = ((a <= d) && (b >= c));
	}
	else answer = ((abc * abd <= 0) && (cda * cdb <= 0));

	if(answer) cout << 1;
	else cout << 0;
    
    return 0;
}