#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int n;
int **paper;

int _negOneCnt = 0;
int _zeroCnt = 0;
int _oneCnt = 0;

void checkPaper(int r, int c, int size);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
	paper = new int*[n];
	for(int i = 0 ; i < n ; i++){
		paper[i] = new int[n];
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> paper[i][j];
		}
	}

	checkPaper(0, 0, n);
	
	for(int i = 0 ; i < n ; i++){
		delete[] paper[i];
	}
	delete[] paper;

	cout << _negOneCnt << "\n";
	cout << _zeroCnt << "\n";
	cout << _oneCnt << "\n";

    return 0;
}

void checkPaper(int r, int c, int curSize){
	int startNum = paper[r][c];

	bool allSame = true;
	for(int i = 0 ; i < curSize ; i++){
		for(int j = 0 ; j < curSize ; j++){
			if(paper[r + i][c + j] != startNum) {
				allSame = false;
				break;
			}
		}
		if(!allSame) break;
	}

	if(allSame){
		switch(startNum){
			case -1:
				_negOneCnt++;
				break;
			case 0:
				_zeroCnt++;
				break;
			case 1:
				_oneCnt++;
				break;
		}
	}
	else{
		int newSize = curSize / 3;
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 3 ; j++){
				checkPaper(r + newSize * i, c + newSize * j, newSize);
			}
		}
	}
}