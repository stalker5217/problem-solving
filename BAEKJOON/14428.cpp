#include <iostream>
#include <vector>
#include <climits>

#define INVALID -1
#define UPDATE 1
#define PRINT 2

using namespace std;

class RMQ{

private:
  int n; // input array 크기
  vector<int> array;
  vector<int> rangeMin; // 구간 최소 값 트리

  int init(int left, int right, int node){
    if(left == right) return rangeMin[node] = left;

    int mid = (left + right) / 2;
    int leftMin = init(left, mid, node * 2);
    int rightMin = init(mid + 1, right, node * 2 + 1);

    return rangeMin[node] = minIdx(leftMin, rightMin);
  }

  int minIdx(int idx1, int idx2){
	  if(idx1 == INVALID) return idx2;
    else if(idx2 == INVALID) return idx1;
    
    if(array[idx1] > array[idx2]) return idx2;
	  else if(array[idx1] < array[idx2]) return idx1;
	  else return idx1 < idx2 ? idx1 : idx2;
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
    if(right < nodeLeft  || nodeRight < left) return INVALID;
    // 교집합이 [nodeLeft, nodeRight] : 미리 계산해둔 노드의 값 반환
    else if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
    // 그 외의 모든 경우 : 재귀적으로 query 호출 후 더 작은 값 반환
    else{
      int mid = (nodeLeft + nodeRight) / 2;
      return minIdx(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
  }

  /** 
   *  @param index 수정하고자 하는 인덱스 값
   *  @param newValue 수정하고자 하는 값
   *  @param node 노드 번호
   *  @param nodeLeft 해당 노드가 나타내는 범위의 시작
   *  @param nodeRight 해당 노드가 나타내는 범위의 끝
   *  
   *  트리의 갱신, 트리 생성 후 값이 바뀐다면 O(lgn)으로 수정이 가능하다  
   */
  int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
    // 새로운 값이 노드가 표현하는 구간과 상관 없으면 무시한다.
    if(index < nodeLeft || index > nodeRight) return rangeMin[node];

    // 리프까지 내려온 경우
    if(nodeLeft == nodeRight) return rangeMin[node];

    else{
      int mid = (nodeLeft + nodeRight) / 2;
      return rangeMin[node] = minIdx(
        update(index, newValue, node*2, nodeLeft, mid),
        update(index, newValue, node*2+1, mid+1, nodeRight)
      );
    }
  }

public:
  RMQ(const vector<int> & _array){
    array.resize(_array.size());
    copy(_array.begin(), _array.end(), array.begin());
    n = array.size();
    rangeMin.resize(n * 4);
    init(0, n-1, 1);
  }

  // 외부 호출을 위한 인터페이스
  int query(int left, int right){
    return query(left, right, 1, 0, n-1);
  }

  // 외부 호출을 위한 인터페이스
  int update(int index, int newValue){
    return update(index, newValue, 1, 0, n-1);
  }

  void setArray(int index, int newValue){
    array[index] = newValue;
  }
};

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> array(n);
	for(int i = 0 ; i < n ; i++) cin >> array[i];

	int m;
	cin >> m;
	RMQ rmq(array);
	for(int i = 0 ; i < m ; i++){
		int cmd;
		cin >> cmd;

		if(cmd == UPDATE){
			int index, newValue;
			cin >> index >> newValue;
      rmq.setArray(index-1, newValue);
			rmq.update(index-1, newValue);
		}
		else if(cmd == PRINT){
			int start, end;
			cin >> start >> end;
			cout << rmq.query(start-1, end-1) + 1 << "\n";
		}
	}
}