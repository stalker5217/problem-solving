#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    int chick;

    cin >> a >> b >> chick;

    if(a+b < 2 * chick){
        cout << a + b;
    }
    else{
        cout << a + b - 2 * chick;
    }

    return 0;
}