#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    for(int i = 0 ; i < 3 ; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    int answer = -1;
    if(arr[2] - arr[1] == arr[1] - arr[0]) answer = 2 * arr[2] - arr[1];
    else if(arr[2] - arr[1] == 2 * (arr[1] - arr[0])) answer = 2 * arr[1] - arr[0];
    else if(2 * (arr[2] - arr[1]) == arr[1] - arr[0]) answer = arr[0] - arr[1] + arr[2];

    cout << answer;

    return 0;
}
