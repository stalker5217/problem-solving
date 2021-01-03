#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 9;
const int AREA_SIZE = 3;

int sdoku[SIZE][SIZE];
bool visit[SIZE][SIZE];
bool isDone = false;

void makeAnswer(int);
bool validationCheck(int, int);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			cin >> sdoku[i][j];
		}
	}
	
	makeAnswer(0);

	for(int i = 0 ; i < SIZE ; i++){
		for(int j = 0 ; j < SIZE ; j++){
			cout << sdoku[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void makeAnswer(const int n){
	if(n == 81){
		isDone = true;
		return;
	}
	
	int row = n / SIZE;
	int col = n % SIZE;
	
	if(sdoku[row][col] == 0){
		int invalidCnt = 0;
		for(int k = 1 ; k <= 9 ; k++){
			sdoku[row][col] = k;
			if( validationCheck(row, col) ){
				makeAnswer(n + 1);
			}
		
			if(isDone) return;
		}
		sdoku[row][col] = 0;
	}
	else makeAnswer(n + 1);
}

bool validationCheck(int row, int col){
	int rowValid[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 0 ; i < SIZE ; i++){
		if(rowValid[sdoku[row][i]] == 0){
			rowValid[sdoku[row][i]] = 1;
		}
		else if(sdoku[row][i] > 0){
			return false;
		}
	}

	int colValid[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 0 ; i < SIZE ; i++){
		if(colValid[sdoku[i][col]] == 0){
			colValid[sdoku[i][col]] = 1;
		}
		else if(sdoku[i][col] > 0){
			return false;
		}
	}

	int areaValid[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	const int rowBase = (row / AREA_SIZE) * AREA_SIZE;
	const int colBase = (col / AREA_SIZE) * AREA_SIZE;
	for(int i = 0 ; i < AREA_SIZE ; i++){
		for(int j = 0 ; j < AREA_SIZE ; j++){
			int curRow = rowBase + i;
			int curCol = colBase + j;
			if(areaValid[sdoku[curRow][curCol]] == 0){
				areaValid[sdoku[curRow][curCol]]= 1;
			}
			else if(sdoku[curRow][curCol] > 0){
				return false;
			}
		}
	}

	return true;
}