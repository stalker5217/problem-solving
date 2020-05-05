#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int heightSize, rowSize, colSize;
int box[100][100][100];

void checkTomato();

typedef struct __coord{
	int h;
	int r;
	int c;
} coord;

int dir[6][3] ={
	{-1, 0, 0},
	{1, 0, 0},
	{0, -1, 0},
	{0, 1, 0},
	{0, 0, -1},
	{0, 0, 1},
};

queue<coord> welldone;
int day = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> colSize >> rowSize >> heightSize;
    for(int i = 0 ; i < heightSize ; i++){
        for(int j = 0 ; j < rowSize ; j++){
            for(int k = 0 ; k < colSize ; k++){
				/**
				 * 1 = 익은 토마토
				 * 0 = 익지 않은 토마토
				 * -1 = 빈 칸
				 */
				
				cin >> box[i][j][k];
				
				if(box[i][j][k] == 1){
					coord co;
					co.h = i;
					co.r = j;
					co.c = k;
					welldone.push(co);
				}
			}
        }
    }

    checkTomato();

    bool isPossible = true;
    for(int i = 0 ; i < heightSize ; i++){
        for(int j = 0 ; j < rowSize ; j++){
			for(int k = 0 ; k < colSize ; k++){
				if(box[i][j][k] == 0){
					isPossible = false;
					break;
				}
			}
			if(!isPossible) break;
		}
		if(!isPossible) break;
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
            coord curPos = welldone.front();
            welldone.pop();

			int h = curPos.h;
            int r = curPos.r;
            int c = curPos.c;

			for(int i = 0 ; i < 6 ; i++){
				if(h + dir[i][0] >= 0 && h + dir[i][0] < heightSize &&
				   r + dir[i][1] >= 0 && r + dir[i][1] < rowSize &&
				   c + dir[i][2] >= 0 && c + dir[i][2] < colSize &&
				   box[h + dir[i][0]][r + dir[i][1]][c + dir[i][2]] == 0)
				{
					box[h + dir[i][0]][r + dir[i][1]][c + dir[i][2]] = 1;
					coord co;
					co.h = h + dir[i][0];
					co.r = r + dir[i][1];
					co.c = c + dir[i][2];
					welldone.push(co);
				}
			}
        }
    }
}