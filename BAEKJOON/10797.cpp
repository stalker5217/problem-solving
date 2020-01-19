#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int target;
    cin >> target;

    int cnt = 0;
    for(int i = 0 ; i < 5 ; i++){
        int carNum;
        cin >> carNum;

        if(carNum == target){
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}