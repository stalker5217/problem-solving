#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int rowSize, colSize;
int box[1000][1000];

void checkTomato();

queue<pair<int, int>> welldone;
int day = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> colSize >> rowSize;
    for(int i = 0 ; i < rowSize ; i++){
        for(int j = 0 ; j < colSize ; j++){
            /**
             * 1 = 익은 토마토
             * 0 = 익지 않은 토마토
             * -1 = 빈 칸
             */
            
            cin >> box[i][j];
            
            if(box[i][j] == 1){
                welldone.push(make_pair(i, j));
            }
        }
    }

    checkTomato();

    bool isPossible = true;
    for(int i = 0 ; i < rowSize ; i++){
        for(int j = 0 ; j < colSize ; j++){
            // cout << box[i][j] << " ";
            if(box[i][j] == 0){
                isPossible = false;
                break;
            }
        }
        if(!isPossible) break;
        // cout << "\n";
    }

    if(isPossible) {cout << day;}
    else {cout << "-1";}

    return 0;
}

void checkTomato(){
    while(true){
        int daySize = welldone.size(); // 이 날 돌릴 사이즈

        if(daySize > 0) day++;
        else break;
        
        for(int a = 0 ; a < daySize ; a++){
            pair<int, int> curPos = welldone.front();
            welldone.pop();

            int i = curPos.first;
            int j = curPos.second;

            if(i-1 >= 0 && (box[i-1][j] == 0)){
                box[i-1][j] = 1;
                welldone.push(make_pair(i-1, j));
            }
            if(i+1 < rowSize && (box[i+1][j] == 0)){
                box[i+1][j] = 1;
                welldone.push(make_pair(i+1, j));
            }
            if(j-1 >= 0 && (box[i][j-1] == 0)){
                box[i][j-1] = 1;
                welldone.push(make_pair(i, j-1));
            }
            if(j+1 < colSize && (box[i][j+1] == 0)){
                box[i][j+1] = 1;
                welldone.push(make_pair(i, j+1));
            }
        }
    }
}