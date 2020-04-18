#define DEBUG 0
#define LOG(string) cout << string

#define UP_CW 0
#define UP_CCW 1
#define FRONT_CW 2
#define FRONT_CCW 3
#define DOWN_CW 4
#define DOWN_CCW 5
#define BACK_CW 6
#define BACK_CCW 7
#define RIGHT_CW 8
#define RIGHT_CCW 9
#define LEFT_CW 10
#define LEFT_CCW 11

#define WHITE 0
#define RED 1
#define YELLOW 2
#define ORANGE 3
#define BLUE 4
#define GREEN 5

#define UP 0
#define FRONT 1
#define DOWN 2
#define BACK 3
#define RIGHT 4
#define LEFT 5

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void simulation(int[6][3][3], const vector<int> &);
void upCW(int[6][3][3]);
void upCCW(int[6][3][3]);
void frontCW(int[6][3][3]);
void frontCCW(int[6][3][3]);
void downCW(int[6][3][3]);
void downCCW(int[6][3][3]);
void backCW(int[6][3][3]);
void backCCW(int[6][3][3]);
void rightCW(int[6][3][3]);
void rightCCW(int[6][3][3]);
void leftCW(int[6][3][3]);
void leftCCW(int[6][3][3]);

void CW(int[3][3]);
void CCW(int[3][3]);

void show(int[6][3][3], int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;

	for(int t =  0 ; t < test_case ; t++){
		int cmdCnt;
		cin >> cmdCnt;

		vector<int> cmdArr;
		for(int i = 0 ; i < cmdCnt ; i++){
			char where;
			char to;
			
			cin >> where >> to;

			if(where == 'U'){
				if(to == '+') cmdArr.push_back(UP_CW);
				else cmdArr.push_back(UP_CCW);
			}
			else if(where == 'F'){
				if(to == '+') cmdArr.push_back(FRONT_CW);
				else cmdArr.push_back(FRONT_CCW);
			}
			else if(where == 'D'){
				if(to == '+') cmdArr.push_back(DOWN_CW);
				else cmdArr.push_back(DOWN_CCW);
			}
			else if(where == 'B'){
				if(to == '+') cmdArr.push_back(BACK_CW);
				else cmdArr.push_back(BACK_CCW);
			}
			else if(where == 'R'){
				if(to == '+') cmdArr.push_back(RIGHT_CW);
				else cmdArr.push_back(RIGHT_CCW);
			}
			else if(where == 'L'){
				if(to == '+') cmdArr.push_back(LEFT_CW);
				else cmdArr.push_back(LEFT_CCW);
			}
		}

		int cube[6][3][3] = {
			{{WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}, {WHITE, WHITE, WHITE}},
			{{RED, RED, RED}, {RED, RED, RED}, {RED, RED, RED}},
			{{YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}, {YELLOW, YELLOW, YELLOW}},
			{{ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}, {ORANGE, ORANGE, ORANGE}},
			{{BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}, {BLUE, BLUE, BLUE}},
			{{GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}, {GREEN, GREEN, GREEN}}
		};

		simulation(cube, cmdArr);
		
		// cout << "UP" << endl; 
		show(cube, UP); 
		// cout << endl;
		// cout << "FRONT" << endl;  show(cube, FRONT); cout << endl;
		// cout << "DOWN" << endl;  show(cube, DOWN); cout << endl;
		// cout << "BACK" << endl;  show(cube, BACK); cout << endl;
		// cout << "RIGHT" << endl;  show(cube, RIGHT); cout << endl;
		// cout << "LEFT" << endl;  show(cube, LEFT); cout << endl;
	}
    
    return 0;
}

void simulation(int cube[6][3][3], const vector<int> & cmdArr){
	for(int cmd : cmdArr){
		switch(cmd){
			case UP_CW: upCW(cube); break;
			case UP_CCW: upCCW(cube); break;
			case FRONT_CW: frontCW(cube); break;
			case FRONT_CCW: frontCCW(cube); break;
			case DOWN_CW: downCW(cube); break;
			case DOWN_CCW: downCCW(cube); break;
			case BACK_CW: backCW(cube); break;
			case BACK_CCW: backCCW(cube); break;
			case RIGHT_CW: rightCW(cube); break;
			case RIGHT_CCW:	rightCCW(cube); break;
			case LEFT_CW: leftCW(cube); break;
			case LEFT_CCW: leftCCW(cube); break;
		}
	}
}

void CW(int cube[3][3]){
	// 0 1 2
	// 3 4 5
	// 6 7 8

	// 6 3 0
	// 7 4 1
	// 8 5 2

	int temp = cube[0][0];
	cube[0][0] = cube[2][0];
	cube[2][0] = cube[2][2];
	cube[2][2] = cube[0][2];
	cube[0][2] = temp;

	temp = cube[0][1];
	cube[0][1] = cube[1][0];
	cube[1][0] = cube[2][1];
	cube[2][1] = cube[1][2];
	cube[1][2] = temp;
}


void upCW(int cube[6][3][3]){
	CW(cube[UP]);
	
	int temp[3];
	temp[0] = cube[LEFT][0][0];
	temp[1] = cube[LEFT][0][1];
	temp[2] = cube[LEFT][0][2];

	cube[LEFT][0][0] = cube[FRONT][0][0];
	cube[LEFT][0][1] = cube[FRONT][0][1];
	cube[LEFT][0][2] = cube[FRONT][0][2];

	cube[FRONT][0][0] = cube[RIGHT][0][0];
	cube[FRONT][0][1] = cube[RIGHT][0][1];
	cube[FRONT][0][2] = cube[RIGHT][0][2];

	cube[RIGHT][0][0] = cube[BACK][0][0];
	cube[RIGHT][0][1] = cube[BACK][0][1];
	cube[RIGHT][0][2] = cube[BACK][0][2];

	cube[BACK][0][0] = temp[0];
	cube[BACK][0][1] = temp[1];
	cube[BACK][0][2] = temp[2];
}

void upCCW(int cube[6][3][3]){
	upCW(cube); upCW(cube); upCW(cube);
}

void frontCW(int cube[6][3][3]){
	CW(cube[FRONT]);
	
	int temp[3];
	temp[0] = cube[LEFT][0][2];
	temp[1] = cube[LEFT][0][5];
	temp[2] = cube[LEFT][0][8];

	cube[LEFT][0][2] = cube[DOWN][0][0];
	cube[LEFT][1][2] = cube[DOWN][0][1];
	cube[LEFT][2][2] = cube[DOWN][0][2];

	cube[DOWN][0][0] = cube[RIGHT][2][0];
	cube[DOWN][0][1] = cube[RIGHT][1][0];
	cube[DOWN][0][2] = cube[RIGHT][0][0];

	cube[RIGHT][0][0] = cube[UP][2][0];
	cube[RIGHT][1][0] = cube[UP][2][1];
	cube[RIGHT][2][0] = cube[UP][2][2];

	cube[UP][2][0] = temp[2]; 
	cube[UP][2][1] = temp[1];
	cube[UP][2][2] = temp[0];
}

void frontCCW(int cube[6][3][3]){
	frontCW(cube); frontCW(cube); frontCW(cube);
}

void downCW(int cube[6][3][3]){
	CW(cube[DOWN]);
	
	int temp[3];
	temp[0] = cube[FRONT][2][0];
	temp[1] = cube[FRONT][2][1];
	temp[2] = cube[FRONT][2][2];

	cube[FRONT][2][0] = cube[LEFT][2][0];
	cube[FRONT][2][1] = cube[LEFT][2][1];
	cube[FRONT][2][2] = cube[LEFT][2][2];

	cube[LEFT][2][0] = cube[BACK][2][0];
	cube[LEFT][2][1] = cube[BACK][2][1];
	cube[LEFT][2][2] = cube[BACK][2][2];

	cube[BACK][2][0] = cube[RIGHT][2][0];
	cube[BACK][2][1] = cube[RIGHT][2][1];
	cube[BACK][2][2] = cube[RIGHT][2][2];

	cube[RIGHT][2][0] = temp[0];
	cube[RIGHT][2][1] = temp[1];
	cube[RIGHT][2][2] = temp[2];
}

void downCCW(int cube[6][3][3]){
	downCW(cube); downCW(cube); downCW(cube);
}

void backCW(int cube[6][3][3]){
	CW(cube[BACK]);
	
	int temp[3];
	temp[0] = cube[RIGHT][0][2];
	temp[1] = cube[RIGHT][1][2];
	temp[2] = cube[RIGHT][2][2];

	cube[RIGHT][0][2] = cube[DOWN][2][2];
	cube[RIGHT][1][2] = cube[DOWN][2][1];
	cube[RIGHT][2][2] = cube[DOWN][2][0];
	
	cube[DOWN][2][0] = cube[LEFT][0][0];
	cube[DOWN][2][1] = cube[LEFT][1][0];
	cube[DOWN][2][2] = cube[LEFT][2][0];

	cube[LEFT][0][0] = cube[UP][0][2];
	cube[LEFT][1][0] = cube[UP][0][1];
	cube[LEFT][2][0] = cube[UP][0][0];

	cube[UP][0][0] = temp[0];
	cube[UP][0][1] = temp[1];
	cube[UP][0][2] = temp[2];
}

void backCCW(int cube[6][3][3]){
	backCW(cube); backCW(cube); backCW(cube);
}

void rightCW(int cube[6][3][3]){
	CW(cube[RIGHT]);
	
	int temp[3];
	temp[0] = cube[UP][0][2];
	temp[1] = cube[UP][1][2];
	temp[2] = cube[UP][2][2];

	cube[UP][0][2] = cube[FRONT][0][2];
	cube[UP][1][2] = cube[FRONT][1][2];
	cube[UP][2][2] = cube[FRONT][2][2];

	cube[FRONT][0][2] = cube[DOWN][0][2];
	cube[FRONT][1][2] = cube[DOWN][1][2];
	cube[FRONT][2][2] = cube[DOWN][2][2];

	cube[DOWN][0][2] = cube[BACK][2][0];
	cube[DOWN][1][2] = cube[BACK][1][0];
	cube[DOWN][2][2] = cube[BACK][0][0];

	cube[BACK][0][0] = temp[2];
	cube[BACK][1][0] = temp[1];
	cube[BACK][2][0] = temp[0];
}

void rightCCW(int cube[6][3][3]){
	rightCW(cube); rightCW(cube); rightCW(cube);
}

void leftCW(int cube[6][3][3]){
	CW(cube[LEFT]);
	
	int temp[3];
	temp[0] = cube[UP][0][0];
	temp[1] = cube[UP][1][0];
	temp[2] = cube[UP][2][0];

	cube[UP][0][0] = cube[BACK][2][2];
	cube[UP][1][0] = cube[BACK][1][2];
	cube[UP][2][0] = cube[BACK][0][2];

	cube[BACK][0][2] = cube[DOWN][2][0];
	cube[BACK][1][2] = cube[DOWN][1][0];
	cube[BACK][2][2] = cube[DOWN][0][0];

	cube[DOWN][0][0] = cube[FRONT][0][0];
	cube[DOWN][1][0] = cube[FRONT][1][0];
	cube[DOWN][2][0] = cube[FRONT][2][0];

	cube[FRONT][0][0] = temp[0];
	cube[FRONT][1][0] = temp[1];
	cube[FRONT][2][0] = temp[2];
}

void leftCCW(int cube[6][3][3]){
	leftCW(cube); leftCW(cube); leftCW(cube);
}

void show(int cube[6][3][3], int where){
	string color = "wryobg";
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			int colorIdx = cube[where][i][j];
			cout << color[colorIdx];
		}
		cout << "\n";
	}
}