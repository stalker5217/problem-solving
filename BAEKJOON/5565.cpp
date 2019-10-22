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

	int total;
	int temp;
	cin >> total;
	for(int i = 0 ; i < 9 ; i++){
		cin >> temp;
		total -= temp;
	}

	cout << total;
	
    return 0;
}
