#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

	for(int i = 1 ; i <= n * 2 - 1 ; i++){
		int sCnt = (i <= n) ? i : (2*n - i);
		for(int s = 0 ; s < sCnt ; s++){
			cout << "*";
		}
		cout << "\n";
	}
    
    return 0;
}
