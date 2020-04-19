#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void backTracking(vector<int> & permu, const int & startPos, const int & maxNum, const int & maxLength);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maxNum;
	int maxLength;
	cin >> maxNum >> maxLength;

	vector<int> sequence;
	backTracking(sequence, 1, maxNum, maxLength);

    return 0;
}

void backTracking(vector<int> & sequence, const int & startPos, const int & maxNum, const int & maxLength){
	if(sequence.size() == maxLength){
		for(int i : sequence){
			cout << i << " ";
		}
		cout << "\n";

		return;
	}
	
	for(int i = startPos ; i <= maxNum ; i++){
		sequence.push_back(i);
		backTracking(sequence, i + 1, maxNum, maxLength);
		sequence.pop_back();
	}
}