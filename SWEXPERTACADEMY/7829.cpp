#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int T;
	cin >> T;

	for(int test_case = 1 ; test_case <= T ; ++test_case){
		int n;
		cin >> n;

		if(n == 1){
			int temp;
			cin >> temp;
			int result = temp * temp;
			cout << "#" << test_case << " " << result << "\n";
			continue;
		}

		vector<int> arr;
		
		for(int i = 0 ; i < n ; i++){
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		int result = arr[0] * arr[arr.size() - 1];
		cout << "#" << test_case << " " << result << "\n";
	}
}