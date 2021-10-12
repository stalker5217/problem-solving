#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	// edge case
	if(n == 0) {
		cout << 1;
		return 0;
	}

	vector<int> count(9, 0);
	while(n > 0) {
		if(n % 10 == 9) count[6]++;
		else count[n % 10]++;
		
		n /= 10;
	}

	count[6] = count[6] % 2 == 0 ? count[6]/2 : count[6]/2 + 1;

	int need = 0;
	for(int i = 0 ; i < count.size() ; i++) need = max(need, count[i]);
	
	cout << need;
    
    return 0;
}