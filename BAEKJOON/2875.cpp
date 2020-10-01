#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int girl, boy, intern;
    cin >> girl >> boy >> intern;

    while(intern > 0){
        if(girl >= boy * 2) girl--;
        else boy--;
        intern--;
    }

    int answer = (girl / 2) > boy ? boy : (girl / 2);
    cout << answer;

    return 0;
}
