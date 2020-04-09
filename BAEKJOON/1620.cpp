#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int pocketmonCnt;
    int qCnt;

    unordered_map<string, string> pocMap;
    cin >> pocketmonCnt >> qCnt;
    for(int i = 1 ; i <= pocketmonCnt ; i++){
        string order = to_string(i);
        string name;
        cin >> name;
        pocMap.insert(make_pair(order, name));
        pocMap.insert(make_pair(name, order));
    }

    for(int i = 0 ; i < qCnt ; i++){
        string findTarget;
        cin >> findTarget;

        cout << pocMap[findTarget] << "\n";
    }

    return 0;
}