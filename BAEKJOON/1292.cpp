#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int start, end;
	cin >> start >> end;

	vector<int> partialSum(end + 1);
	partialSum[0] = 0; // dummy

	int cnt = 0;
	int current = 1;
	for(int i = 1 ; i <= end ; i++, cnt++) {
		if(cnt >= current) {
			cnt = 0;
			current++;
		}

		partialSum[i] = partialSum[i-1] + current;
	}

	cout << partialSum[end] - partialSum[start - 1];

    return 0;
}