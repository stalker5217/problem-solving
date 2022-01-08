#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
	int n;
	vector<int> oddCnt;

	int init(const vector<int> & arr, int left, int right, int node) {
		if(left == right)
			return oddCnt[node] = arr[left] % 2;
		
		int mid = (left + right) / 2;
		int leftOddCnt = init(arr, left, mid, node * 2);
		int rightOddCnt = init(arr, mid + 1, right, node * 2 + 1);

		return oddCnt[node] = leftOddCnt + rightOddCnt;
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	    if(right < nodeLeft  || nodeRight < left) 
			return 0;
	    else if(left <= nodeLeft && nodeRight <= right) 
			return oddCnt[node];
	    else{
    	  	int mid = (nodeLeft + nodeRight) / 2;
      		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
    	}
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if(index < nodeLeft || index > nodeRight) 
			return oddCnt[node];

		// 리프까지 내려온 경우
		if(nodeLeft == nodeRight) 
			return oddCnt[node] = newValue % 2;
		
		else{
			int mid = (nodeLeft + nodeRight) / 2;
			return oddCnt[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
		}
	}
	
public:
	SegmentTree(const vector<int> & arr) {
		n = arr.size();
		oddCnt.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}

	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> arr[i];

	SegmentTree segmentTree(arr);

	int m; cin >> m;
	for(int i = 0 ; i < m ; i++) {
		int command; cin >> command;
		// 값 변경
		if(command == 1) {
			int index, value;
			cin >> index >> value;
			segmentTree.update(index, value);
		}
		// 짝수 개수 출력
		else if(command == 2) {
			int l, r;
			cin >> l >> r;
			int totalCnt = r - l + 1;
			cout << totalCnt - segmentTree.query(l, r) << "\n";
		}
		// 홀수 개수 출력
		else if(command == 3) {
			int l, r;
			cin >> l >> r;
			cout << segmentTree.query(l, r) << "\n";
		}
	}

	return 0;
}