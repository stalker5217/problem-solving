#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool checkPal(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool isPrime[1210001];
	memset(isPrime, 1, sizeof(bool) * 1210001);
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i = 2 ; i < 1100 ; i++){
		if(isPrime[i] == true){
			for(int a = i * 2 ; a <= 1210000 ; a += i){
				isPrime[a] = false;
			}
		}
	}

	int n;
	cin >> n;
	for(int i = n ; true ; i++){
		if(isPrime[i] == true && checkPal(i)){
			cout << i;
			break;
		}
	}
    return 0;
}

bool checkPal(int value){
	vector<int> arr;
	while(true){
		arr.push_back(value % 10);
		value /= 10;
		if(value == 0){
			break;
		}
	}

	int start = 0;
	int end = arr.size() - 1;
	bool isPal = true;
	while(true){
		if(start >= end){
			break;
		}

		if(arr[start] != arr[end]){
			isPal = false;
			break;
		}

		start++;
		end--;
	}

	return isPal;
}