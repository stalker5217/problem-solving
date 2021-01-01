#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int cnt;
	cin >> cnt;
	vector<int> solution(cnt, 0);
	for(int i = 0 ; i < cnt ; i++){
		cin >> solution[i];
	}

	int left = 0, minLeft = 0;
	int right = cnt - 1, minRight = cnt - 1;
	int minVal = solution[left] + solution[right];
	minVal = minVal > 0 ? minVal : -minVal;
	while(left < right){
		int sum = solution[left] + solution[right];
		int sumAbs = sum > 0 ? sum : -sum;
		if(sumAbs < minVal){
			minVal = sumAbs;
			minLeft = left;
			minRight = right;
		}

		if(sum == 0) break;
		else if(sum > 0) right--;
		else left++;
	}

	cout << solution[minLeft] << " " << solution[minRight];
	
    return 0;
}