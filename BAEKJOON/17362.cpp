#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	n %= 8;
	int answer = 0;
	if(n == 0) answer = 2;
	else if(n <= 5) answer = n;
	else answer = 10 - n;

	cout << answer;
    
    return 0;
}