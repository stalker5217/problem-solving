#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool existOdd = false;
	vector<int> arr;
	for(int i = 0 ; i < 7 ; i++){
		int tmp;
		cin >> tmp;
		if(tmp % 2 == 1) existOdd = true;
		arr.push_back(tmp);
	}

	if(!existOdd){
		cout << "-1\n";
		return 0;
	}
	
	int sum = 0;
	int minVal = 987654321;
	for(int i = 0 ; i < arr.size() ; i++){
		if(arr[i] % 2 == 1){
			sum += arr[i];
			minVal = (minVal > arr[i]) ? arr[i] : minVal;
		}
	}

	cout << sum << "\n";
	cout << minVal << "\n";
    
    return 0;
}
