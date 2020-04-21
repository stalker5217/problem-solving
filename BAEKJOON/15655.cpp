#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void backTracking(int);

vector<int> sequence;
vector<int> source;
int maxLength;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCnt;
	cin >> numCnt >> maxLength;

	for(int i = 0 ; i < numCnt ; i++){
		int temp;
		cin >> temp;
		source.push_back(temp);
	}
	sort(source.begin(), source.end());

	backTracking(0);

    return 0;
}

void backTracking(int offset){
	if(sequence.size() == maxLength){
		for(int i : sequence){
			cout << i << " ";
		}
		cout << "\n";

		return;
	}
	
	for(int i = offset ; i < source.size() ; i++){
		sequence.push_back(source[i]);
		backTracking(i + 1);
		sequence.pop_back();
	}
}