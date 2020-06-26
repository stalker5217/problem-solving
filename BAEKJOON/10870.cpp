#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int fibo(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}

int fibo(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibo(n-1) + fibo(n-2);
}