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

void backTracking();

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

	backTracking();

    return 0;
}

void backTracking(){
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
	
	for(int i = 0 ; i < source.size() ; i++){
        sequence.push_back(source[i]);
        backTracking();
        sequence.pop_back();
	}
}