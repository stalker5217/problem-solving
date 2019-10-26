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

	int n;
	cin >> n;
    if(n % 2 == 0){
		cout << "CY";
	}
	else{
		cout << "SK";
	}
    
    return 0;
}
