#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0 ; i < 3 ; i++){
		int back = 0;
		int belly = 0;
		int temp;
		for(int j = 0 ; j < 4 ; j++){
			cin >> temp;
			temp == 0 ? belly++ : back++;
		}

		if(belly == 1){
			cout << "A" << "\n";
		}
		else if(belly == 2){
			cout << "B" << "\n";
		}
		else if(belly == 3){
			cout << "C" << "\n";
		}
		else if(belly == 4){
			cout << "D" << "\n";
		}
		else{
			cout << "E" << "\n";
		}
	}
    
    return 0;
}
