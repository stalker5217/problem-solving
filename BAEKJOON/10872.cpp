#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	if( n == 0 || n == 1){
		cout << "1";
		return 0;
	}

	long long result = 1;

	for(int i = n ; i > 1 ; i--){
		result *= i;
	}

	cout << result;

	return 0;
}