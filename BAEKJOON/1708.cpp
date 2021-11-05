#define DEBUG 0
#define LOG(string) cout << string
#define ll long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <functional>

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

	int n; cin >> n;
	vector<pair<ll, ll> > points;

	for(int i = 0 ; i < n ; i++) {
		int a, b;
		cin >> a >> b;
		points.push_back({a, b});
	}

	// 아래, 왼쪽부터 시작하도록 정렬
	sort(points.begin(), points.end(), [](auto a, auto b) {
		if(a.second == b.second) return a.first < b.first;
		else return a.second < b.second;
	});

	function<ll (pair<ll, ll>, pair<ll, ll>)> dist = [](pair<ll, ll> a, pair<ll, ll> b) {
		ll width = b.first - a.first;
		ll height = b.second - a.second;

		return width * width + height * height;
	};

	// 각도 기반 정렬
	sort(points.begin() + 1 , points.end(), [&](auto a, auto b) {
		int ccwResult = ccw(points[0], a, b);
		if(ccwResult == 0) return dist(points[0], a) < dist(points[0], b);

		return ccwResult > 0;
	});

	stack<pair<ll, ll> > st;
	st.push(points[0]);
	st.push(points[1]);
	
	for(int i = 2 ; i < n ; i++) {
		pair<ll, ll> a, b;
		while(st.size() >= 2) {
			b = st.top(); st.pop();
			a = st.top();

			if(ccw(a, b, points[i]) > 0) {
				st.push(b);
				break;
			}
		}

		st.push(points[i]);
	}

	cout << st.size();
    
    return 0;
}