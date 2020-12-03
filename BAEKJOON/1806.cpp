#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> arr(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	int sum = 0;
	int start = 0, end = 0;
	int minLen = 123456;
	while(start <= end && end <= n){
		if(sum < s) sum += arr[end++];
		else{
			minLen = min(minLen, end - start);
			sum -= arr[start++];
		}
	}

	if(minLen == 123456) minLen = 0;

	cout << minLen;
    
	return 0;
}