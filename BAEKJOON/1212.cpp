#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;

    string firstSet[8] = {"0", "1", "10", "11", "100", "101", "110", "111"}; 
    string normalSet[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    cout << firstSet[str[0] - '0'];
    for(int i = 1 ; i < str.length() ; i++){
        cout << normalSet[str[i] - '0'];
    }

    return 0;
}