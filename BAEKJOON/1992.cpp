#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int picture[64][64];
int n;

void compress(int, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char temp;
            cin >> temp;
            
            picture[i][j] = temp - '0';
        }
    }

    compress(0, 0, n);

    return 0;
}

void compress(int r, int c, int curSize){
    int base = picture[r][c];
    bool allSame = true;
    for(int i = r ; i < r + curSize ; i++){
        for(int j = c ; j < c + curSize ; j++){
            if(base != picture[i][j]){
                allSame = false;
                break;
            }
        }
    }

    if(allSame){
        // cout << "[r = " << r << ", c = " << c << "] size = " << curSize << " ";
        // cout << base << "\n";

        cout << base;
    }

    else{
        cout << "(";
        int newSize = curSize / 2;
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                compress(r + newSize * i, c + newSize * j, newSize);
            }
        }
        cout << ")";
    }
    
}
