#define DEBUG 0
#define LOG(string) cout << string

#define FRONT 0
#define BACK 1

#include <iostream>
#include <cstring>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;
	for(int t = 0 ; t < test_case ; t++){
		string command;		
		int initSize;
		string arrString;
		
		cin >> command >> initSize >> arrString;
		
		deque<int> arr;
		// string 가공
		arrString = arrString.substr(1, arrString.size() - 2);		
		stringstream ss(arrString);
		string val;
		while(getline(ss, val, ',')){
			arr.push_back(stoi(val));
		}
		
		int deleteBase = FRONT;
		bool existError = false;
		// cout << arr.size();
		for(int i = 0 ; i < command.size() ; i++){
			if(command[i] == 'R'){
				deleteBase = (deleteBase == FRONT) ? BACK : FRONT;
			}
			else if(command[i] == 'D'){
				if(arr.size() == 0){
					existError = true;
					break;
				}
				else if(deleteBase == FRONT){
					arr.pop_front();
				}
				else if(deleteBase == BACK){
					arr.pop_back();
				}
			}
		}

		if(existError){
			cout << "error";
		}
		else{
			if(deleteBase == FRONT){
				cout << "[";
				for(int i = 0 ; i < arr.size() ; i++){
					cout << arr[i];
					if(i < arr.size() - 1){
						cout << ",";
					}
				}
				cout << "]";
			}
			else if(deleteBase == BACK){
				cout << "[";
				for(int i = arr.size() - 1 ; i >= 0 ; i--){
					cout << arr[i];
					if(i > 0){
						cout << ",";
					}
				}
				cout << "]";
			}
		}
		cout << "\n";
	}
    return 0;
}
