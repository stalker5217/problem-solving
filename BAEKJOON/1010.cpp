#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int testCase;
	cin >> testCase;
	while(testCase--) {
		long long n, m;
		cin >> n >> m;
		
		n = (m - n > n) ? n : m - n;
		long long answer = 1;
		for(long long i = m ; i > m - n ; i--) answer *= i;
		for(long long i = 1 ; i <= n ; i++) answer /= i;

		cout << answer << "\n";
	}

    return 0;
}