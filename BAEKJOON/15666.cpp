#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

void backTracking(int);

vector<int> sequence;
vector<int> source;
unordered_map<string, int> isPrinted;

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
		string key;
        for(int i : sequence){
			key += to_string(i);
            key += ".";
		}
        
        if(isPrinted[key] != 1){
            for(int i : sequence) cout << i << " ";
            cout << "\n";
            isPrinted[key] = 1;
        }
		
		return;
	}
	
	for(int i = offset ; i < source.size() ; i++){
        sequence.push_back(source[i]);
        backTracking(i);
        sequence.pop_back();
	}
}