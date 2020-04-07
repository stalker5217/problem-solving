#include <iostream>
#include <vector>

using namespace std;

int main(){
    int arr[11];

    arr[0] = 0; // dummy
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i = 4 ; i <= 10 ; i++){
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    int test_case;
    cin >> test_case;
    for(int t = 0 ; t < test_case ; t++){
        int idx; 
        cin >> idx;
        cout << arr[idx] << "\n";
    }

    return 0;
}