#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;
	deque<int> card;
	for(int i = 1 ; i <= n ; i++){
		card.push_back(i);
	}

	while(true){
		if(card.size() <= 1){
			break;
		}

		card.pop_front();
		int a = card.front();
		card.pop_front();
		card.push_back(a);
	}

	cout << card[0];
    
    return 0;
}
