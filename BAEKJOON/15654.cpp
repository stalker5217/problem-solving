#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void backTracking(vector<int> & sequence, const vector<int> & source, vector<bool> & isPicked, const int & maxLength);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCnt;
	int maxLength;
	cin >> numCnt >> maxLength;

	vector<int> source;
	vector<bool> isPicked; isPicked.resize(numCnt);
	for(int i = 0 ; i < numCnt ; i++){
		int temp;
		cin >> temp;
		source.push_back(temp);
	}
	sort(source.begin(), source.end());

	vector<int> sequence;
	backTracking(sequence, source, isPicked, maxLength);

    return 0;
}

void backTracking(vector<int> & sequence, const vector<int> & source, vector<bool> & isPicked, const int & maxLength){
	if(sequence.size() == maxLength){
		for(int i : sequence){
			cout << i << " ";
		}
		cout << "\n";

		return;
	}
	
	for(int i = 0 ; i < source.size() ; i++){
		if(isPicked[i] == false){
			sequence.push_back(source[i]); isPicked[i] = true;
			backTracking(sequence, source, isPicked, maxLength);
			sequence.pop_back(); isPicked[i] = false;
		}
	}
}