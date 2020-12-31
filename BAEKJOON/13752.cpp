#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0 ; i < n ; i++){
		int cnt;
		cin >> cnt;
		for(int i = 0 ; i < cnt ; i++) cout << "=";
		cout << "\n";
	}
    
    return 0;
}