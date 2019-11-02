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

    int arr[2002];
	memset(arr, 0, sizeof(int) * 2002);

	int N;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		arr[temp + 1001] = 1;
	}

	for(int i = 0 ; i < 2002 ; i++){
		if(arr[i] == 1){
			cout << i - 1001 << " ";
		}
	}

    return 0;
}
