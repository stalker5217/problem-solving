#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool * visit;
void permutation(vector<int> & permu, const int & maxNum, const int & maxLength);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maxNum;
	int maxLength;
	cin >> maxNum >> maxLength;

	vector<int> permu;
	visit = new bool[maxNum + 1];

	permutation(permu, maxNum, maxLength);

    return 0;
}

void permutation(vector<int> & permu, const int & maxNum, const int & maxLength){
	if(permu.size() == maxLength){
		for(int i : permu){
			cout << i << " ";
		}
		cout << "\n";

		return;
	}
	
	for(int i = 1 ; i <= maxNum ; i++){
		if(visit[i] == false){
			permu.push_back(i); visit[i] = true;
			permutation(permu, maxNum, maxLength);
			permu.pop_back(); visit[i] = false;
		}
	}
}