#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class RangeMinimumQuery{

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
  RangeMinimumQuery(const vector<int> & array){
    n = array.size();
    rangeMin.resize(n * 4);
    init(array, 0, n-1, 1);
  }

  // 외부 호출을 위한 인터페이스
  int query(int left, int right){
    return query(left, right, 1, 0, n-1);
  }
};

class RangeMaximumQuery{

private:
  int n; // input array 크기
  vector<int> rangeMin; // 구간 최소 값 트리

  // 최소 값으로 초기화
  int init(const vector<int> & array, int left, int right, int node){
    if(left == right) return rangeMin[node] = array[left];

    int mid = (left + right) / 2;
    int leftMin = init(array, left, mid, node * 2);
    int rightMin = init(array, mid + 1, right, node * 2 + 1);

    return rangeMin[node] = max(leftMin, rightMin);
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
    if(right < nodeLeft  || nodeRight < left) return INT_MIN;
    // 교집합이 [nodeLeft, nodeRight] : 미리 계산해둔 노드의 값 반환
    else if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
    // 그 외의 모든 경우 : 재귀적으로 query 호출 후 더 작은 값 반환
    else{
      int mid = (nodeLeft + nodeRight) / 2;
      return max(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
  }

public:
  RangeMaximumQuery(const vector<int> & array){
    n = array.size();
    rangeMin.resize(n * 4);
    init(array, 0, n-1, 1);
  }

  // 외부 호출을 위한 인터페이스
  int query(int left, int right){
    return query(left, right, 1, 0, n-1);
  }
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> array(n);
	for(int i = 0 ; i < n ; i++) cin >> array[i];

	RangeMinimumQuery rangeMinimumQuery(array);
	RangeMaximumQuery rangeMaximumQuery(array);	
	for(int i = 0 ; i < m ; i++){
		int start, end;
		cin >> start >> end;
		cout << rangeMinimumQuery.query(start-1, end-1) << " " << rangeMaximumQuery.query(start-1, end-1) << "\n";
	}
}