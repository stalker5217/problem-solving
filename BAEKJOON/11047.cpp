#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> value;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        value.push_back(tmp);
    }

    int cnt = 0;
    for(int i = value.size() - 1 ; i >= 0 && k > 0 ; i--){
        if(k >= value[i]) {
            cnt += k / value[i];
            k %= value[i];
        }
    }    

    cout << cnt;

    return 0;
}
