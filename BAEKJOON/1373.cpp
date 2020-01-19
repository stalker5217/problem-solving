#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;

    int firstCnt = (str.length() % 3 == 0) ? 3 : str.length() % 3;
    int val = 0;
    for(int i = 0 ; i < firstCnt ; i++){
        val *= 2;
        val += (str[i] - '0');
    }
    cout << val;

    int cnt = 0;
    val = 0;
    for(int i = firstCnt ; i < str.length() ; i++){
        cnt++;
        
        val *= 2;
        val += (str[i] - '0');

        if(cnt >= 3){
            cnt = 0;
            cout << val;
            val = 0;
        }
    }

    return 0;
}