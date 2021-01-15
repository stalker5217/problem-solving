#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

    int *arr = new int[1000001];
	vector<int> trace;
	for(int i = 2; i <= n ; i++){
		int minVal = arr[i-1];
		if(i % 2 == 0) minVal = (arr[i/2] > minVal) ? minVal : arr[i/2];
		if(i % 3 == 0) minVal = (arr[i/3] > minVal) ? minVal : arr[i/3];

		arr[i] = minVal + 1;
	}

	cout << arr[n] << "\n";
	while(true){
		cout << n << " ";
		
		if(n == 1) break;

		if(arr[n] == arr[n-1] + 1) n -=1;
		else if(n % 2 == 0 && arr[n] == arr[n/2] + 1) n /= 2;
		else if(n % 3 == 0 && arr[n] == arr[n/3] + 1) n /= 3;
	}


	delete[] arr;
    
    return 0;
}