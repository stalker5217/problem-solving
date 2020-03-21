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

    while(1){
		vector<int> arr;
		for(int i = 0 ; i < 3 ; i++){
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}

		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0){
			break;
		}

		sort(arr.begin(), arr.end());

		int a = arr[0] * arr[0] + arr[1] * arr[1];
		int b = arr[2] * arr[2];

		if(a == b){
			cout << "right\n";
		}
		else{
			cout << "wrong\n";
		}
	}

    return 0;
}
