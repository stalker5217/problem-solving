#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, test_case;
	cin >> n >> test_case;

	vector<int> partialSum(n+1);
	partialSum[0] = 0;
	for(int i = 1 ; i <= n; i++){
		int tmp;
		cin >> tmp;
		partialSum[i] += partialSum[i-1] + tmp;
	}

	while(test_case--){
		int start, end;
		cin >> start >> end;
		cout << partialSum[end] - partialSum[start-1] << "\n";
	}
    
    return 0;
}
