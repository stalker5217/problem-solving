#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int cnt, target;
	cin >> cnt >> target;
	int arr[10000];
	for(int i = 0 ; i < cnt ; i++) cin >> arr[i];
	
	int start = 0, end = 0;
	int sum = 0;
	int answer =  0;
	while(start <= end){
		if(sum == target) answer++;
		
		if(sum >= target) sum -= arr[start++];
		else if(sum < target){
			if(end >= cnt) break;
			sum += arr[end++];
		}

	}

	cout << answer;
	
    return 0;
}