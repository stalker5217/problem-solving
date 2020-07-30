#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int cutCnt(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;
    cout << cutCnt(row, col);

    return 0;
}

int cutCnt(int row, int col){
    if(row == 1 && col == 1) return 0;
    else if(row > col) return row * cutCnt(1, col) + (row - 1);
    else return col * cutCnt(row, 1) + (col - 1);
}