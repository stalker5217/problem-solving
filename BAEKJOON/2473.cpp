#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int cnt;
	cin >> cnt;
	vector<long long> solution(cnt, 0);
	for(int i = 0 ; i < cnt ; i++){
		cin >> solution[i];
	}
	sort(solution.begin(), solution.end());

	int minStart = 0;
	int minLeft = 1;
	int minRight = cnt - 1;
	long long minVal = solution[minStart] + solution[minLeft] + solution[minRight];
	minVal = minVal > 0 ? minVal : -minVal;

	for(int start = 0 ; start < cnt ; start++){
		int left = start + 1;
		int right = cnt - 1;
		
		while(left < right){
			long long sum = solution[start] + solution[left] + solution[right];
			long long sumAbs = sum > 0 ? sum : -sum;
			if(sumAbs < minVal){
				minVal = sumAbs;
				minStart = start;
				minLeft = left;
				minRight = right;
			}

			if(sum == 0) break;
			else if(sum > 0) right--;
			else left++;
		}
	}
	
	cout << solution[minStart] << " " << solution[minLeft] << " " << solution[minRight];
	
    return 0;
}