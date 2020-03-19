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

	// bucket
	int arr[10001] = {0, };
	int n, temp;

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> temp;
		arr[temp]++;
	}

	for(int i = 1 ; i <= 10000 ; i++){
		if(arr[i] > 0){
			for(int j = 0 ; j < arr[i] ; j++){
				cout << i << "\n";
			}
		}
	}

    return 0;
}
