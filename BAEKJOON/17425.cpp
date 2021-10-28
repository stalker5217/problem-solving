#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int MAX = 1000000;
	long long* f = new long long[MAX+1];

	for(int i = 1 ; i <= MAX ; i++) 
		for(int j = 1 ; i * j <= MAX ; j++) f[i * j] += i;
		
	long long* g = new long long[MAX+1];
	for(int i = 1 ; i <= MAX ; i++) g[i] = g[i-1] + f[i];
	
	int testCase;
	cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		cout << g[n] << "\n";
	}
	
	delete f; delete g;	

	return 0;
}