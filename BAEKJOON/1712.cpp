#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int fixedCost;
	int floatingCost;
	int price;
	cin >> fixedCost >> floatingCost >> price;

	if(floatingCost >= price) cout << -1;
	else cout << fixedCost / (price - floatingCost) + 1;

	return 0;  
}
