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
    
	int arr[101];
	memset(arr, 0, sizeof(int) * 101);

	
	int avg;
	int sum = 0;
	for(int i = 0 ; i < 10 ; i++){
		int temp;
		cin >> temp;
		sum += temp;
		temp /= 10;
		if(arr[temp] == -1){
			arr[temp] = 1;
		}
		else{
			arr[temp]++;
		}
	}

	avg = sum / 10;

	int maxCnt = 0;
	int maxVal;

	for(int i = 1 ; i <= 100 ; i++){
		if(arr[i] > maxCnt){
			maxCnt = arr[i];
			maxVal = i * 10;
		}
	}

	cout << avg << "\n" << maxVal;

    return 0;
	
}
