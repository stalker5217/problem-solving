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

    while(true){
		int num;
		cin >> num;

		// escape sequence
		if(num == 0){
			break;
		}

		vector<int> arr;
		// 배열화
		while(true){
			int n = num % 10;
			arr.push_back(n);
			num /= 10;

			if(num == 0){
				break;
			}
		}

		// 팰린드롬 체크
		int startIdx = 0;
		int endIdx = arr.size() - 1;
		bool isPal = true;
		while(startIdx < endIdx){
			if(arr[startIdx] != arr[endIdx]) {
				isPal = false;
				break;
			}
			
			startIdx++;
			endIdx--;
		}

		if(isPal){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
    
    return 0;
}
