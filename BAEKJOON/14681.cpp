#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
	cin >> x >> y;

	int ans = 0;
	if(x > 0 && y > 0) ans = 1;
	else if(x < 0 && y > 0) ans = 2;
	else if(x < 0 && y < 0) ans = 3;
	else if(x > 0 && y < 0) ans = 4;

	cout << ans;
    
    return 0;
}
