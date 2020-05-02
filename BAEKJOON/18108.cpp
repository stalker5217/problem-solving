#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int bYear;
	cin >> bYear;

    cout << bYear - 543;
    
    return 0;
}
