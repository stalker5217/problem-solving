#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

char ** star;
void makeStar(int, int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	
	star = new char*[n];
	for(int i = 0 ; i < n ; i++) star[i] = new char[n];

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			star[i][j] = ' ';
		}
	}

	makeStar(0, 0, n);

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << star[i][j];
		}
		cout << "\n";
	}
	
	for(int i = 0 ; i < n ; i++) delete star[i];
	delete star;

    return 0;
}

void makeStar(int i, int j, int size){
	if(size == 1){
		star[i][j] = '*';
	}
	else{
		int newSize = size/3;
		for(int a = 0 ; a < 3 ; a++){
			for(int b = 0 ; b < 3 ; b++){
				if(a == 1 && b == 1) continue;
				makeStar(a * newSize + i, b * newSize + j, newSize);
			}
		}
	}
}