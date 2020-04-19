#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int personPerArea;
	int area;
	cin >> personPerArea >> area;

	int total = personPerArea * area;
	for(int i = 0 ; i < 5 ; i++){
		int a; cin >> a;
		cout << a - total << " ";
	}
    
    return 0;
}
