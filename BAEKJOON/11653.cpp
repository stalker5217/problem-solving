#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 2 ; n > 1 ; i++){
		while(n % i == 0){
			cout << i << "\n";
			n /= i;
		}
	}
    
    return 0;
}