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

    int distance;
	cin >> distance;

	int answer = (distance % 5 == 0) ? distance / 5 : distance / 5 + 1;

	cout << answer;
    
    return 0;
}
