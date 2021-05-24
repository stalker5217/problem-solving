#define DEBUG 0
#define LOG(string) cout << string
#define ll long long

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
	ll result = (a.first * b.second) + (b.first * c.second) + (c.first * a.second) - (a.second * b.first) - (b.second * c.first) - (c.second * a.first);

	if(result > 0) return 1; // 반시계
	else if(result < 0) return -1; // 시계
	else return 0; // 평행
}

struct disjointSet{
  vector<int> parent;
  vector<int> rank;

  disjointSet(int n)
  : parent(n), rank(n, 1)
  {
    for(int i = 0 ; i < n ; i++){
      parent[i] = i;
    }
  }

  // 경로 압축 최적화
  int find(int u) {
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
  }

  // u, v가 속해 있는 각각의 트리를 합친다
  void merge(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) ++rank[v];
  }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int lineCnt;
	cin >> lineCnt;

	vector<pair<pair<ll, ll>, pair<ll, ll> > > lines;
	vector<int> parent;
	disjointSet set(lineCnt);

	for(int i = 0 ; i < lineCnt ; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lines.push_back({{x1, y1}, {x2, y2}});
	}

	for(int i = 0 ; i < lineCnt ; i++){
		pair<ll, ll> a = lines[i].first;
		pair<ll, ll> b = lines[i].second;

		for(int j = i + 1 ; j < lineCnt ; j++){
			pair<ll, ll> c = lines[j].first;
			pair<ll, ll> d = lines[j].second;

			int abc = ccw(a, b, c);
			int abd = ccw(a, b, d);
			int cda = ccw(c, d, a);
			int cdb = ccw(c, d, b);

			bool isCross;
			// 평형
			if(abc * abd == 0 && cda * cdb == 0){
				if(a > b) swap(a, b);
				if(c > d) swap(c, d);

				isCross = ((a <= d) && (b >= c));
			}
			else isCross = ((abc * abd <= 0) && (cda * cdb <= 0));

			if(isCross){
				set.merge(i, j);
			}
		}
 	}

	 int cnt  = 0;
	 unordered_map<int, int> groupSize;
	 for(int i = 0 ; i < lineCnt ; i++){
		int root = set.find(i);
		if(i == root) cnt++;
		groupSize[root]++;
	 }

	cout << cnt << "\n";
	cout << max_element(groupSize.begin(), groupSize.end(),
						[] (const pair<int, int> & p1, const pair<int, int> & p2) -> bool{
							return p1.second < p2.second;
						})->second;

    return 0;
}