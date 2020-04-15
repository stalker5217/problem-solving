#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> & a, const pair<int, int> & b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int, int> > conferenceArr;
    for(int i = 0 ; i < n ; i++){
        int start, end;
        cin >> start >> end;
        conferenceArr.push_back(make_pair(start, end));
    }

    sort(conferenceArr.begin(), conferenceArr.end(), compare);

    pair<int, int> curPair = make_pair(-1, -1);
    int conferCnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(curPair.second <= conferenceArr[i].first){
            conferCnt++;
            curPair = conferenceArr[i];
        }
    }

    cout << conferCnt;

    return 0;
}

bool compare(const pair<int, int> & a, const pair<int, int> & b){
    if(a.second < b.second) return true;
    else if(a.second > b.second) return false;
    else if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    else return false;
}