#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cups = {0, 1, 0 ,0};
    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        swap(cups[a], cups[b]);
    }

    for(int i = 1 ; i < cups.size() ; i++){
        if(cups[i]){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}