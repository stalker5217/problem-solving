#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> mVector;
    for(int i = 0 ; i < 3 ; i++){
        int temp;
        cin >> temp;
        mVector.push_back(temp);
    }
    sort(mVector.begin(), mVector.end());

    for(int i = 0 ; i < 3 ; i++){
       cout << mVector[i] << " ";
    }
    
    return 0;
}
