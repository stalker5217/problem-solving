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

    int w, h, x, y;
	cin >> x >> y >> w >> h;

	int minWidth = ((w-x) > x) ? x : (w-x);
	int minHeight = ((h-y) > y) ? y : (h-y);

	int min = (minWidth > minHeight) ? minHeight : minWidth;

	cout << min;
    
    return 0;
}
