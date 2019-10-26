#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

int gcd(int, int);
int lcm(int, int);

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
	cin >> a >> b;

	int gcdVal = gcd(a, b);
	int lcmVal = a * b / gcdVal;

	cout << gcdVal << "\n" << lcmVal;
    
    return 0;
}

int gcd(int a, int b){
	while(1){
		if(a > b){
			swap(a, b);
		}

		if(b % a == 0){
			return a;
		}

		b = b % a;
	}
}