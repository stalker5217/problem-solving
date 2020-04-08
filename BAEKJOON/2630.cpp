#include <iostream>
#include <vector>

#define WHITE 0
#define BLUE 1

using namespace std;

int map[128][128];

void divideMap(int, int, int);

int whiteCnt;
int blueCnt;

int main(){
    int mapSize;
    cin >> mapSize;

    for(int i = 0 ; i < mapSize ; i++){
        for(int j = 0 ; j < mapSize ;j++){
            cin >> map[i][j];
        }
    }

    divideMap(0, 0, mapSize);

    cout << whiteCnt << "\n";
    cout << blueCnt << "\n";

    return 0;
}

void divideMap(int startRow, int startCol, int size){
    int startColor = map[startRow][startCol];
    bool sameAll = true;
    for(int i = startRow ; i < startRow + size ; i++){
        for(int j = startCol ; j < startCol + size ; j++){
            if(map[i][j] != startColor){
                sameAll = false;
                break;
            }
        }
    }

    if(sameAll && startColor == BLUE) blueCnt++;
    else if(sameAll && startColor == WHITE) whiteCnt++;
    else{
        divideMap(startRow, startCol, size/2);
        divideMap(startRow + size/2, startCol, size/2);
        divideMap(startRow, startCol + size/2, size/2);
        divideMap(startRow + size/2, startCol + size/2, size/2);
    }  

}