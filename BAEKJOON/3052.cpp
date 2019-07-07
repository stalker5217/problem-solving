#include <iostream>
#include <cstring>

using namespace std;

int main(){
	bool existVal[42];
	memset(existVal, false, sizeof(bool) * 42);

	for(int i = 0 ; i < 10 ; i++){
		int temp;
		cin >> temp;
		existVal[temp % 42] = true;
	}

	int trueCnt = 0;
	for(int i = 0 ; i < 42 ; i++){
		if(existVal[i] == true){
			trueCnt++;
		}
	}

	cout << trueCnt;
}