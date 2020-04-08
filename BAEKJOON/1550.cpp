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

    string hexa;
	cin >> hexa;

	int h = 1;
	int ans = 0;
	for(int i = hexa.size() - 1 ; i >= 0 ; i--, h*= 16){
		int cur;
		switch(hexa[i]){
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
			cur = 10 + hexa[i] - 'A';
			break;
		default:
			cur = hexa[i] - '0';
			break;
		}

		ans += cur * h;	
	}
    
	cout << ans;
    
    return 0;
}
