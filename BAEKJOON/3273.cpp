#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    int target;
    cin >> target;

    sort(arr.begin(), arr.end());
    int front = 0, end = arr.size() - 1;
    int cnt = 0;
    while(front < end) {
        int sum = arr[front] + arr[end];
        if(sum == target) {
            cnt++;
            front++;
        }
        else if(sum < target) front++;
        else if(sum > target) end--;
    }
    
    cout << cnt;

    return 0;
}