#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> solution(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> solution[i];

	sort(solution.begin(), solution.end());

	int left = 0 , right = solution.size() - 1;
	int minLeft = 0, minRight = solution.size() - 1;
	int minVal = abs(solution[left] + solution[right]);
	while(left < right) {
		int sum  = solution[left] + solution[right];
		if(abs(sum) < minVal) {
			minLeft = left;
			minRight = right;
			minVal = abs(sum);
		} 

		if(sum < 0) left++;
		else right--;
	}

	cout << solution[minLeft] << " " << solution[minRight];
    
    return 0;
}