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

	int sum = 0;
    for(int i = 0 ; i < 5 ; i++){
		int temp;
		cin >> temp;
		sum += temp * temp;
	}

	cout << sum % 10;
    
    return 0;
}
