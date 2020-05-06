#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
	cin >> a >> b;

	cout << a * (b-1) + 1;

    return 0;
}
