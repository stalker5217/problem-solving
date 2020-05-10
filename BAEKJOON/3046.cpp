#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, avg;
	cin >> a >> avg;

	cout << 2 * avg - a;
    
    return 0;
}
