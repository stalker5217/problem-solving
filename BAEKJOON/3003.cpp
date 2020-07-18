#define DEBUG 0
#define LOG(string) cout << string

#define KING 1
#define QUEEN 1
#define ROOK 2
#define BISHOP 2
#define KNIGHT 2
#define PAWNS 8

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int cnt[6] = {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWNS};
	for(int i = 0 ; i < 6 ; i++){
		int tmp;
		cin >> tmp;
		cout << cnt[i] - tmp << " ";
	}
	
    
    return 0;
}
