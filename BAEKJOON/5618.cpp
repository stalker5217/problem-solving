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

	if(n == 2){
		int a, b;
		cin >> a >> b;
		int smaller = min(a, b);
		for(int i = 1 ; i <= smaller ; i++){
			if(a % i == 0 && b % i == 0) cout << i << "\n";
		}
	}

	else if(n == 3){
		int a, b, c;
		cin >> a >> b >> c;
		int smaller = min(a, min(b, c));
		for(int i = 1 ; i <= smaller ; i++){
			if(a % i == 0 && b % i == 0 && c % i == 0) cout << i << "\n";
		}
	}
}
