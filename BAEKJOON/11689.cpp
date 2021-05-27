#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
	cin >> n;

	long long result = n;
	long long p = 2;
	while(p * p <= n){
		if(n % p == 0){
			result = result / p * (p-1);
			while(n % p == 0) n /= p;
		}
		p++;
	}

	if(n > 1) result = result / n * (n-1);

	cout << result;
    
    return 0;
}