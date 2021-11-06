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

    int N, M;
	vector<int> source;
	vector<int> target;

	cin >> N;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin >> temp;
		source.push_back(temp);
	}
    sort(source.begin(), source.end());

	cin >> M;
	for(int i = 0 ; i < M ; i++){
		int temp;
		cin >> temp;
		target.push_back(temp);
	}

	for(int i = 0 ; i < target.size() ; i++){
		if(binary_search(source.begin(), source.end(), target[i])) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

    return 0;
}
