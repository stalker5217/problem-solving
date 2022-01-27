#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
	int n;
	vector<long long> rangeMul;

	long long init(const vector<int> & arr, int left, int right, int node) {
		if(left == right) return rangeMul[node] = arr[left];
		else {
			int mid = (left + right) / 2;
			rangeMul[node] = init(arr, left, mid, node * 2) * init(arr, mid + 1, right, node * 2 + 1);

			return rangeMul[node];
		}
	}

	long long update(int index, long long newValue, int node, int nodeLeft, int nodeRight) {
		// 상관 없는 구간
		if(index < nodeLeft || index > nodeRight) return rangeMul[node];

		// 리프 노트
		if(nodeLeft == nodeRight) return rangeMul[node] = newValue;
		else {
			int mid = (nodeLeft + nodeRight) / 2;
			rangeMul[node] = update(index, newValue, node * 2, nodeLeft, mid) * update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
			
			return rangeMul[node];
		}
	}

	long long query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if(right < nodeLeft || nodeRight < left) return 1;
		else if(left <= nodeLeft && nodeRight <= right) return rangeMul[node];
		else {
			int mid = (nodeLeft + nodeRight) / 2;
			long long result = query(left, right, node * 2, nodeLeft, mid) * query(left, right, node * 2 + 1, mid + 1, nodeRight);

			return result;
		}
	}

public:
	SegmentTree(const vector<int> & arr) {
		n = arr.size();
		rangeMul.resize(n * 4);

		init(arr, 0, n-1, 1);
	}

	long long update(int index, long long newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}

	long long query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	while(cin >> n >> k) {
		vector<int> arr(n + 1);
		for(int i = 1 ; i <= n ; i++) {
			cin >> arr[i];
			if(arr[i] > 0) arr[i] = 1;
			else if(arr[i] < 0) arr[i] = -1; 
		}

		SegmentTree segmentTree(arr);

		for(int i = 0 ; i < k ; i++) {
			char command; cin >> command;
			if(command == 'C') {
				int i, v; cin >> i >> v;
				if(v > 0) v = 1;
				else if(v < 0) v = -1;
				
				segmentTree.update(i, v);
			}
			else if(command == 'P') {
				int i, j; cin >> i >> j;
				int result = segmentTree.query(i, j);
				switch(result) {
					case -1: cout << "-"; break;
					case 0: cout << "0"; break;
					case 1: cout << "+"; break;
				}
			}
		}

		cout << "\n";
	}

	return 0;
}