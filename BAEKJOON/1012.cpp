#include <iostream>
#include <cstring>

using namespace std;

int map[50][50];
int row, col;
int bugCnt;

void initMap();
void setArea(int, int);

int main(){
   int test_case;
   cin >> test_case;

   for(int t = 0 ; t < test_case ; t++){
       initMap();
       
       int n;
       cin >> row >> col >> n;

       for(int i = 0 ; i < n ; i++){
           int r, c;
           cin >> r >> c;
           map[r][c] = 1;
       }

       bugCnt = 0;
       for(int i = 0 ; i < row ; i++){
           for(int j = 0 ; j < col ; j++){
               if(map[i][j] == 1){
                   bugCnt++;
                   setArea(i, j);
               }
           }
       }

       cout << bugCnt << "\n";
   }
    
    return 0;
}

void initMap(){
    for(int i = 0 ; i < 50 ; i++){
        memset(map[i], 0, sizeof(int) * 50);
    }
}

void setArea(int r, int c){
    map[r][c] = 2;

    if(r - 1 >= 0 && map[r-1][c] == 1) setArea(r-1, c);
    if(r + 1 < row && map[r+1][c] == 1) setArea(r+1, c);
    if(c - 1 >= 0 && map[r][c-1] == 1) setArea(r, c-1);
    if(c + 1 < col && map[r][c+1] == 1) setArea(r, c+1);
}