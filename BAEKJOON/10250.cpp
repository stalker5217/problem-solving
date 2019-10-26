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

	int T;
	cin >> T;
	for(int test_case  = 1 ; test_case <= T ; test_case++){
		int totalFloor;
		int totalHo;
		int k;
		cin >> totalFloor >> totalHo >> k;

		vector<int> roomList;
		for(int ho = 1 ; ho <= totalHo ; ho++){
			for(int floor = 1 ; floor <= totalFloor ; floor++){
				int temp = floor * 100 + ho;
				roomList.push_back(temp);
			}
		}

		cout << roomList[k - 1] << "\n";
	}
    
    return 0;
}
