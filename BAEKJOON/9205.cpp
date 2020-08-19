#define DEBUG 0
#define LOG(string) cout << string

#define MMAX 102

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

bool isConnected[MMAX][MMAX];

bool bfs(const int &, const int &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	cin >> test_case;
	for(int t = 0 ; t < test_case ; t++){
		int conv_cnt;
		cin >> conv_cnt;
		vector<pair<int, int> > coord;
		for(int i = 0 ; i < conv_cnt + 2; i++){
			int x, y;
			cin >> x >> y;
			coord.push_back(make_pair(x, y));
		}

		// Connection 정보 생성
		memset(isConnected, false, sizeof(bool) * MMAX * MMAX);
		for(int i = 0 ; i < coord.size() ; i++){
			for(int j = 0 ; j < coord.size() ; j++){
				if(i == j) continue;

				int dist = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
				
				// 20병으로 천미터까지 가능
				if(dist <= 1000){
					isConnected[i][j] = true;
					isConnected[j][i] = true;
				}
			}
		}

		bool result = bfs(0, coord.size());

		if(result) cout << "happy\n";
		else cout << "sad\n";
	}

    return 0;
}

bool bfs(const int & start, const int & size){
	vector<bool> visit(size);
	visit.assign(size, false);

	queue<int> q;
	q.push(start);
	visit[start] = true;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(cur == size - 1) return true;

		for(int i = 0 ; i < size ; i++){
			if(isConnected[cur][i] && !visit[i]){
				visit[i] = true;
				q.push(i);
			}
		}
	}

	return false;
}