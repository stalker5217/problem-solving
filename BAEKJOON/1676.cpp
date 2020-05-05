#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

    int _fiveCnt = 0;
	for(int i = 5 ; i <= n ; i *= 5){
		_fiveCnt += n / i;
	}

	cout << _fiveCnt;
    
    return 0;
}
