#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int diagonal;
	int a, b;

	cin >> diagonal >> a >> b;
	double ratio = diagonal / sqrt(((a * a) + (b * b)));
	
	int width = a * ratio;
	int height = b * ratio;

	cout << width << " " << height;
    
    return 0;
}