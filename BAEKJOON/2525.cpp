#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int hour, minute;
    cin >> hour >> minute;

    int addVal;
    cin >> addVal;

    minute += addVal;

    hour += minute / 60;
    hour %= 24;
    
    minute %= 60;
    
    cout << hour << " " << minute;

    return 0;
}