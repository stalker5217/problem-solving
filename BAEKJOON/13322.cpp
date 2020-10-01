#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    for(int i = 0 ; i < str.size() ; i++) cout << i << "\n";

    return 0;
}