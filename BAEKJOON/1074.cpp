#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void zTravel(int, int, int);
int targetR, targetC;
int visitCnt = 0;
bool findOK;

pair<int, int> dir[4] = {
    make_pair(0, 0),
    make_pair(0, 1),
    make_pair(1, 0),
    make_pair(1, 1)
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    
    cin >> n >> targetR >> targetC;
    zTravel(n, 0, 0);
    cout << visitCnt;

    return 0;
}

void zTravel(int n, int r, int c){
    if(n == 1){
        for(int i = 0 ; i < 4 ; i++){
			if(r + dir[i].first == targetR && c + dir[i].second == targetC){
                findOK = true;
                return;
            }
			visitCnt++;
        }

        return;
    }

    if(!findOK) {
		if(targetR >= r && targetC >= c && targetR < r + pow(2, n-1) && targetC < c + pow(2, n-1)) zTravel(n-1, r, c);
		else visitCnt += pow(2, n-1) * pow(2, n-1);
	}
    if(!findOK) {
		if(targetR >= r && targetC >= c + pow(2, n-1) && targetR < r + pow(2, n-1) && targetC < c + pow(2, n-1) * 2) zTravel(n-1, r, c + pow(2, n-1));
		else visitCnt += pow(2, n-1) * pow(2, n-1);
	}
    if(!findOK){
		if(targetR >= r + pow(2, n-1) && targetC >= c && targetR < r + pow(2, n-1) * 2 && targetC < c + pow(2, n-1)) zTravel(n-1, r + pow(2, n-1), c);
		else visitCnt += pow(2, n-1) * pow(2, n-1);
	} 
    if(!findOK){
		if(targetR >= r + pow(2, n-1) && targetC >= c + pow(2, n-1) && targetR < r + pow(2, n-1) * 2 && targetC < c + pow(2, n-1) * 2) zTravel(n-1, r + pow(2, n-1), c + pow(2, n-1));
		else visitCnt += pow(2, n-1) * pow(2, n-1);
	} 
}
