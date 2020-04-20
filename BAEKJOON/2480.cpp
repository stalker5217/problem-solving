#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
	cin >> a >> b >> c;

	int ans;
	if(a == b && a == c) ans = 10000 + a * 1000;
	else if(a == b) ans = 1000 + a * 100;
	else if(a == c) ans = 1000 + a * 100;
	else if(b == c) ans = 1000 + b * 100;
	else{
		int mymax = ((a > b) ? a : b) > c ? ((a > b) ? a : b) : c;
		ans = mymax * 100;
	}

	cout << ans;
    
    return 0;
}
