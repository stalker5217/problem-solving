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

    long long a, b, c;
	cin >> a >> b >> c;
	auto ans = a + b + c;
	cout << ans;
    
    return 0;
}
