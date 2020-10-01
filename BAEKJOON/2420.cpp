#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
	cin >> a >> b;

	cout << abs(a - b);
    
    return 0;
}
