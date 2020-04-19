#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 1 ; i <= n * 2 ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(j % 2 == i % 2) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}