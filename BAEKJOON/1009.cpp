#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;
	for(int t = 0 ; t < test_case ; t++){
		int a, b;
		cin >> a >> b;

		int answer = 1;
		for(int i = 0 ; i < b ; i++){
			answer *= a;
			answer %= 10;
		}
		answer = (answer == 0) ? 10 : answer;

		cout << answer << "\n";
	}
    
    return 0;
}
