#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#define INF 87654321
using namespace std;
int m[51][51];
int visited[51][51];//바꾼수 기록
int n;
int di[] = { 1, 0, -1, 0 };
int dj[] = { 0, 1, 0, -1 };
typedef pair<int, int> point;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)scanf("%1d", &m[i][j]);
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)visited[i][j] = INF;
	visited[1][1] = 0;
	queue<point> q;
	q.push(point(1, 1));
	while (!q.empty()) {
		point here = q.front(); q.pop();
		int hi = here.first;
		int hj = here.second;
		//cout << hi << " " << hj << endl;
		for (int i = 0; i < 4; ++i) {
			int ni = hi + di[i];
			int nj = hj + dj[i];
			if (ni<1 || ni>n || nj<1 || nj>n)continue;
			if (visited[ni][nj] <= visited[hi][hj])continue;//등호가 들어가는게 중요
			if (m[ni][nj] == 1) {
				visited[ni][nj] = visited[hi][hj];
				q.push(point(ni, nj));
			}
			else {
				visited[ni][nj] = visited[hi][hj] + 1;
				q.push(point(ni, nj));
			}
		}
	}
	printf("%d\n", visited[n][n]);
	return 0;
}