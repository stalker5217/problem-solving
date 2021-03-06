#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int ccw(int, int, int, int, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    int x1, y1;
	int x2, y2;
	int x3, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int result = ccw(x1, y1, x2, y2, x3, y3);

	if(result > 0) cout << "1";
	else if(result < 0) cout << "-1";
	else cout << "0";
    
    return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2- x1) * (y3 - y1) - (y2- y1) * (x3 - x1);
} 