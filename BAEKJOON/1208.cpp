#define DEBUG 0
#define LOG(string) cout << string
#define ll long long

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

	int half = (n / 2);

	vector<int> left(1 << half);
	for(int i = 0 ; i < left.size() ; i++){
		for(int j = 0 ; j < half ; j++){
			if(i & (1 << j)) left[i] += arr[j];
		}
	}
	sort(left.begin(), left.end());

	vector<int> right(1 << (n - half));
	for(int i = 0 ; i < right.size() ; i++){
		for(int j = 0 ; j < (n - half) ; j++){
			if(i & (1 << j)) right[i] += arr[half + j];
		}
	}
	sort(right.begin(), right.end(), greater<int>());

	int leftIdx = 0, rightIdx = 0;
	long long result = 0;

	while(leftIdx < left.size() && rightIdx < right.size()){
		long long sum = left[leftIdx] + right[rightIdx];
		if(sum < s) leftIdx++;
		else if(sum > s) rightIdx++;
		else{
			long long leftCnt = 1, rightCnt = 1;
			leftIdx++; rightIdx++;
			while(leftIdx < left.size() && left[leftIdx] == left[leftIdx - 1]){
				leftIdx++;
				leftCnt++;
			}

			while(rightIdx < right.size() && right[rightIdx] == right[rightIdx - 1]){
				rightIdx++;
				rightCnt++;
			}

			result += (leftCnt * rightCnt);
		}
	}

	if(s == 0) result--;
	cout << result;

    return 0;
}