#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class RMQ{
private:
  int n; // input array 크기
  vector<int> rangeMin; // 구간 최소 값 트리

  // 최소 값으로 초기화
  int init(const vector<int> & array, int left, int right, int node){
    if(left == right) return rangeMin[node] = array[left];

    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, node * 2);
    int rightMin = init(array, mid + 1, right, node * 2 + 1);

    return rangeMin[node] = min(leftMin, rightMin);
  }

  /**
   *  @param left 쿼리 범위의 시작
   *  @param right 쿼리 범위의 끝
   *  @param node 노드 번호
   *  @param nodeLeft 해당 노드가 나타내는 범위의 시작
   *  @param nodeRight 해당 노드가 나타내는 범위의 끝
   * 
   *  쿼리가 표현하는 범위와 노드가 표현하는 범위의 교집합의 최소 원소를 반환한다.
   */
  int query(int left, int right, int node, int nodeLeft, int nodeRight){
    // 교집합이 공집합 : 두 구간은 겹치지 않으므로 INFINITE 반환
    if(right < nodeLeft  || nodeRight < left) return INT_MAX;
    // 교집합이 [nodeLeft, nodeRight] : 미리 계산해둔 노드의 값 반환
    else if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
    // 그 외의 모든 경우 : 재귀적으로 query 호출 후 더 작은 값 반환
    else{
      int mid = (nodeLeft + nodeRight) / 2;
      return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
  }

public:
  RMQ(const vector<int> & array){
    n = array.size();
    rangeMin.resize(n * 4);
    init(array, 0, n-1, 1);
  }

  // 외부 호출을 위한 인터페이스
  int query(int left, int right){
    return query(left, right, 1, 0, n-1);
  }
};

RMQ* rmq;

vector<vector<int> > adj;
vector<int> depth;

int nextSerial = 0;
vector<int> trip;
vector<int> locInTrip;
vector<int> no2Serial;
vector<int> serial2No;

void resourceInit(int);
void dfs(int, int);
int lca(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;
	resourceInit(n);

	for(int i = 0 ; i < n - 1 ; i++){
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// Depth, Parent 구하기
	dfs(1, 1);
	rmq = new RMQ(trip);
	
	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << "\n";
	}

    return 0;
}

void resourceInit(int n){
	adj.resize(n+1);
	depth.resize(n+1);
	locInTrip.resize(n+1);
	no2Serial.resize(n+1);
	serial2No.resize(n+1);
}

void dfs(int node, int curDepth){
	// 노드에 일련 번호 부여
	no2Serial[node] = nextSerial;
	serial2No[nextSerial] = node;
	nextSerial++;
	
	depth[node] = curDepth;
	
	locInTrip[node] = trip.size();
	trip.push_back(no2Serial[node]);

	for(int child : adj[node]){
		if(depth[child] == 0){
			dfs(child, curDepth + 1);
			trip.push_back(no2Serial[node]);
		}
	}
}

int lca(int a, int b){
	int u = locInTrip[a];
	int v = locInTrip[b];

	if(u > v) swap(u, v);

	return serial2No[rmq->query(u, v)];
}