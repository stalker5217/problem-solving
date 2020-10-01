#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;
	while(true){
		int target;
		cin >> target;
		if(target == 0) break;

		if(target % n == 0) cout << target << " is a multiple of " << n << ".\n";
		else cout << target << " is NOT a multiple of " << n << ".\n";
	}
    
    return 0;
}
