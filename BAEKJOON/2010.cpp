#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
    }

    cout << sum - n + 1;


    return 0;
}