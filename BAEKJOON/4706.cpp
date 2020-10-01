#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
		double a, b;
		cin >> a >> b;

		if(a == 0 && b == 0){
			break;
		}

		double r = b / a;
		double v = sqrt(1 - (r * r));

		cout << fixed;
		cout.precision(3);
		cout << v << "\n";
	}
    
    return 0;
}
