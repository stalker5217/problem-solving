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

    int N;
	cin >> N;

	for(int i = 1 ; i < 2 * N ; i++){
		int aCondition = (i <= N) ? i : (2 * N - i);
		int bCondition = 2 * (N - i) > 0 ?  2 * (N - i) : 2 * (i - N);
		int cCondition = (i <= N) ? i : (2 * N - i);
		for(int a = 0 ; a < aCondition; a++){
			cout << "*";
		}
		for(int b = 0 ; b < bCondition ; b++){
			cout << " ";
		}
		for(int c = 0 ; c < cCondition ; c++){
			cout << "*";
		}
		cout << "\n";
	}

    return 0;
}
