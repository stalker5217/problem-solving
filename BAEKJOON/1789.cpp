#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long sum;
	cin >> sum;

	long long start = 1, end = sum;
	while(start <= end) {
		long long mid = (start + end) / 2;

		if(mid * (mid + 1) / 2 > sum) end = mid - 1;
		else start = mid + 1;
	}

	cout << start - 1;
}