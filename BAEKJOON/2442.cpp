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
	
	for(int i = 1 ; i <= N ; i++){
		for(int a = 0 ; a < N-i ; a++)
			cout << " ";
		
		for(int b = 0 ; b < 2 * i - 1 ; b++)
			cout << "*";

		cout << "\n";
	}
    
    return 0;
}
