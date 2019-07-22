#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> arr;

    int temp;
    for(int i = 0 ; i < N ; i++){
        cin >> temp;

        if(temp == 0){
            arr.pop_back();
        }
        else{
            arr.push_back(temp);
        }
    }

    int sum = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        sum += arr[i];
    }

    cout << sum;

    return 0;
}