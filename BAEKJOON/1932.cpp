#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height;
	cin >> height;

	vector<vector<int> > triangle;
	for(int i = 1 ; i <= height ; i++){
		vector<int> cur;
		for(int j = 0 ; j < i ; j++){
			int temp;
			cin >> temp;
			cur.push_back(temp);
		}
		triangle.push_back(cur);
	}

	for(int i = 1 ; i < triangle.size() ; i++){
		for(int j = 0 ; j < triangle[i].size() ; j++){
			if(j == 0) triangle[i][j] += triangle[i-1][j];
			else if(j == triangle[i].size() - 1) triangle[i][j] += triangle[i-1][j-1];
			else triangle[i][j] += (triangle[i-1][j-1] > triangle[i-1][j]) ? triangle[i-1][j-1] : triangle[i-1][j];
		}
	}

	cout << *max_element(triangle[height-1].begin(), triangle[height-1].end());

	return 0;
}
