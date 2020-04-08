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

    int len;
	cin >> len;

	long long r = 1;
	long long hash = 0;
	vector<long long> hashArr;
	for(int i = 0 ; i < len ; i++){
		char curChar;
		cin >> curChar;
		curChar -= ('a' - 1);

		int a = curChar;
		hash += (a * r) % 1234567891;
		r = ((r % 1234567891) * 31) % 1234567891;
	}
    
	cout << hash % 1234567891;

    return 0;
}
