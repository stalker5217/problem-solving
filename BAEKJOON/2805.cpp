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

    int n, goal;
    cin >> n >> goal;
    vector<int> trees;
    int maxVal = 0;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        if(maxVal < temp){
            maxVal = temp;
        }
        trees.push_back(temp);
    }
    
    int start = 0;
    int end = maxVal;
    int ans = start;
    while(true){
        if(start > end){
            break;
        }

        int height = (start + end) / 2;
        long long sum = 0;
        for(int i = 0 ; i < trees.size() ; i++){
            int get = (trees[i] - height > 0) ? (trees[i] - height) : 0;
            sum += get;
        }

        if(sum >= goal){
            ans = height;
            start = height + 1;
        }
        else{
            end = height - 1;
        }
    }

	cout << ans;
    
    return 0;
}
