#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;
	while(test_case--){
		long long x, y;
		cin >> x >> y;
		long long dist = y - x;
		
		long long i = 1;
		while(i * i <= dist){
			i++;
		}

		long long mid = ((i-1) * (i-1) + i * i) / 2;
		if((i-1) * (i-1) == dist) cout << i * 2 - 3 << "\n";
		else if(dist <= mid) cout << i * 2 - 2 << "\n";
		else cout << i * 2 - 1  << "\n";
	}
    
    return 0;
}