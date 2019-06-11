#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	freopen("GNS_test_input.txt", "r", stdin);

	int T;
	cin >> T;


	for(int test_case = 1 ; test_case <= T ; ++test_case){
		string strNum;
		int N;

		cin >> strNum; // #1, #2, ... 읽기.
		cin >> N;

		vector<int> arr;
		for(int i = 0 ; i < N ; i++){
			cin >> strNum;

			if(strNum.compare("ZRO") == 0){
				arr.push_back(0);
			}

			else if(strNum.compare("ONE") == 0){
				arr.push_back(1);
			}

			else if(strNum.compare("TWO") == 0){
				arr.push_back(2);
			}

			else if(strNum.compare("THR") == 0){
				arr.push_back(3);
			}

			else if(strNum.compare("FOR") == 0){
				arr.push_back(4);
			}

			else if(strNum.compare("FIV") == 0){
				arr.push_back(5);
			}

			else if(strNum.compare("SIX") == 0){
				arr.push_back(6);
			}

			else if(strNum.compare("SVN") == 0){
				arr.push_back(7);
			}

			else if(strNum.compare("EGT") == 0){
				arr.push_back(8);
			}

			else if(strNum.compare("NIN") == 0){
				arr.push_back(9);
			}
		}

		sort(arr.begin(), arr.end());

		cout << "#" << test_case << "\n";
		for(int i = 0 ; i < N ; i++){
			if(arr[i] == 0){
				cout << "ZRO ";
			}

			else if(arr[i] == 1){
				cout << "ONE ";
			}

			else if(arr[i] == 2){
				cout << "TWO ";
			}

			else if(arr[i] == 3){
				cout << "THR ";
			}

			else if(arr[i] == 4){
				cout << "FOR ";
			}

			else if(arr[i] == 5){
				cout << "FIV ";
			}

			else if(arr[i] == 6){
				cout << "SIX ";
			}

			else if(arr[i] == 7){
				cout << "SVN ";
			}

			else if(arr[i] == 8){
				cout << "EGT ";
			}

			else if(arr[i] == 9){
				cout << "NIN ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}