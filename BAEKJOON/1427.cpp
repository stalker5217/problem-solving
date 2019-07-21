#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    if(a > b)
        return true;
    else
        return false;
}

int main(){
    int N;      // 1 ~ 1,000,000,000
    cin >> N;

    vector<int> arr;

    while(true){
        if(N == 0)
            break;

        arr.push_back(N % 10);
        N /= 10;
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0 ; i < arr.size() ; i++){
        cout << arr[i];
    }


    return 0;
}