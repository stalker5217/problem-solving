#define DEBUG 0
#define LOG(string) cout << string
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r;
	cin >> r;

	double euclid = r * r * M_PI;
	double taxi = r * r * 2;
	
	cout << fixed;
	cout.precision(6);
	cout << euclid << "\n";
	cout << taxi;
    
    return 0;
}
