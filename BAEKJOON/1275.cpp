#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree{

private:
	vector<long long> tree;

public:
	FenwickTree(int n)
	: tree(n+1)
	{}

	long long sum(int pos){
		long long ret = 0;
		while(pos > 0){
			ret += tree[pos];
			pos &= (pos - 1);
		}

		return ret;
	}

	void add(int pos, long long val){
		while(pos < tree.size()){
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<long long> array(n+1);
	FenwickTree fenwickTree(n);

	for(int i = 1 ; i <= n ; i++){
		cin >> array[i];
		fenwickTree.add(i, array[i]);
	}
	
	for(int i = 0 ; i < m ; i++){
		int start, end, index;
		long long value;
		cin >> start >> end >> index >> value;

		if(start > end) swap(start, end);
		cout << fenwickTree.sum(end) - fenwickTree.sum(start - 1) << "\n";
		fenwickTree.add(index, value - array[index]);
		array[index] = value;
	}
}