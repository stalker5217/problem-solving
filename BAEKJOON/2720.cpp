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
		int changes;
		cin >> changes;
		
		cout << changes / 25 << " ";
		changes %= 25;

		cout << changes / 10 << " ";
		changes %= 10;

		cout << changes / 5 << " ";
		changes %= 5;

		cout << changes / 1 << "\n";
	}
    
    return 0;
}
