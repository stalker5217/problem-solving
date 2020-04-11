#define DEBUG 0
#define LOG(string) cout << string

#define YES 1
#define NO 0

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int mSet[21];

	memset(mSet, NO, sizeof(int) * 21);
	
	int cmdCnt;
	cin >> cmdCnt;

	for(int i = 0 ; i < cmdCnt ; i++){
		string cmd;
		int val;
		
		cin >> cmd;
		if(cmd.compare("add") == 0){
			cin >> val;
			mSet[val] = YES;
		}
		else if(cmd.compare("remove") == 0){
			cin >> val;
			mSet[val] = 0;
		}
		else if(cmd.compare("check") == 0){
			cin >> val;
			if(mSet[val] == NO){
				cout << "0\n";
			}
			else{
				cout << "1\n";
			}
		}
		else if(cmd.compare("toggle") == 0){
			cin >> val;
			if(mSet[val] == NO) mSet[val] = YES;
			else mSet[val] = NO;
		}
		else if(cmd.compare("all") == 0){
			memset(mSet, YES, sizeof(int) * 21);
		}
		else if(cmd.compare("empty") == 0){
			memset(mSet, NO, sizeof(int) * 21);
		}
	}

    return 0;
}
