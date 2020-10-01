#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1;
    int x2, y2;
    int x3, y3;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x4 = x1^x2^x3;
    int y4 = y1^y2^y3;
    cout << x4 << " " << y4;

    return 0;
}