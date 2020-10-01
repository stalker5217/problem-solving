#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
	cin >> a >> b >> c >> d;

	int seconds = a + b + c + d;

	cout << seconds / 60 << "\n";
	cout << seconds % 60;
    
    return 0;
}
