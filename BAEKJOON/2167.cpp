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

	int arr[300][300];
	int N, M, K;

	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> arr[i][j];
		}
	}

	cin >> K;
	int i, j, x, y;
	for(int k = 0 ; k < K ; k++){
		cin >> i >> j >> x >> y;
		int sum = 0;
		for(int a = i-1; a < x ; a++){
			for(int b = j-1; b < y ; b++){
				sum += arr[a][b];
			}
		}
		cout << sum << "\n";
	}
	
    return 0;
}
