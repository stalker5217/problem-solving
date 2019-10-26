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

	int apartment[15][15];
	for(int i = 0 ; i < 15 ; i++){
		memset(apartment[i], 0 , sizeof(int) * 15);
	}

	// 0층부터 존재
	for(int i = 0 ; i < 15 ; i++){
		apartment[0][i] = i;
	}
	// 1호에는 한 명이 산다
	for(int i = 0 ; i < 15 ; i++){
		apartment[i][1] = 1;
	}

	for(int i = 1 ; i < 15 ; i++){
		for(int j = 2 ; j < 15 ; j++){
			apartment[i][j] = apartment[i][j-1] + apartment[i-1][j];
		}	
	}
	
	int cnt;
	int k, n;
	cin >> cnt;
	for(int i = 0 ; i < cnt ; i++){
		cin >> k >> n;
		cout << apartment[k][n] << "\n";
	}

    return 0;
}
