#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int hour, minute, second;
	int cookTime;

	cin >> hour >> minute >> second >> cookTime;

	second += cookTime;

	minute += second / 60;
	second %= 60;

	hour += minute / 60;
	minute %= 60;

	hour %= 24;

	cout << hour << " " << minute << " " << second;
    
    return 0;
}
