#include <iostream>
#include <vector>

#define UPDATE 1
#define PRINT 2

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

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> array(n+1);
	FenwickTree fenwickTree(n);
	for(int i = 1 ; i <= n ; i++){
		cin >> array[i];
		fenwickTree.add(i, array[i]);
	}
	
	for(int i = 0 ; i < m + k ; i++){
		int cmd;
		cin >> cmd;

		if(cmd == UPDATE){
			int index;
			long long value;
			cin >> index >> value;
      		
			fenwickTree.add(index, value - array[index]);
			array[index] = value;
		}
		else if(cmd == PRINT){
			int start, end;
			cin >> start >> end;
			cout << fenwickTree.sum(end) - fenwickTree.sum(start - 1) << "\n";
		}
	}
}