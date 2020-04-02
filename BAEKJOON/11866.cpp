#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void deleteEl(vector<int> & permu, int index);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
	cin >> n >> k;

	vector<int> permu;
	for(int i = 1 ; i <= n ; i++){
		permu.push_back(i);
	}

	vector<int> yosef;
	int preIndex = 0;
	int curIndex;
	for(int i = 1 ; i <= n ; i++){
		int curIndex = (preIndex + k - 1) % permu.size();
		preIndex = curIndex;
		yosef.push_back(permu[curIndex]);
		deleteEl(permu, curIndex);
	}

	cout << "<";
	for(int i = 0 ; i < yosef.size() ; i++){
		cout << yosef[i];
		if(i == yosef.size() - 1){
			cout << ">";
		}
		else{
			cout << ", ";
		}
	}
    
    return 0;
}

void deleteEl(vector<int> & permu, int index){
	for(int i = index ; i < permu.size() - 1 ; i++){
		permu[i] = permu[i+1];
	}
	permu.pop_back();
}
