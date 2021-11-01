#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size; cin >> size;
	vector<int> arr(size);
	for(int i = 0 ; i < size ; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	
	int target; cin >> target;

	int baseIndex = lower_bound(arr.begin(), arr.end(), target) - arr.begin(); 

	int startCnt = target - arr[baseIndex - 1];
	int endCnt = arr[baseIndex] - target;

	if(startCnt == 0 || endCnt == 0) cout << "0";
	else cout << startCnt * endCnt - 1;

    return 0;
}