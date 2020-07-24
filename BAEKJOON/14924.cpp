#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int s, t, d;
	cin >> s >> t >> d;

	cout << d / (2 * s) * t;
}