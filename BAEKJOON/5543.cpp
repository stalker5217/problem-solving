#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, h2, h3, w1, w2;
	cin >> h1 >> h2 >> h3;
	cin >> w1 >> w2;

	int minh = min(h3, min(h1, h2));
	int minw = min(w1, w2);

	int sum = minh + minw - 50;

	cout << sum;
    
    return 0;
}
