#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	
	int * arr = new int[n + 1] {0,};
	for(int i = 1 ; i <= n ; i++){
		int minVal = 4; // 최대 4개 합으로 모든 수 나타낼 수 있음
		for(int j = 1 ; j*j <= i ; j++){
			minVal = (minVal > arr[i - j*j] + 1) ? arr[i - j*j] + 1 : minVal;
		}
		arr[i] = minVal;
	}

	cout << arr[n];
	delete[] arr;
	  
    return 0;
}
