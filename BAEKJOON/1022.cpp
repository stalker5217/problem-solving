#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	const int MAX_VAL = 10001;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	r1 += (MAX_VAL / 2); c1 += (MAX_VAL / 2);
	r2 += (MAX_VAL / 2); c2 += (MAX_VAL / 2);

	const int rowLen = r2 - r1 + 1;
	const int colLen = c2 - c1 + 1;
	vector<vector<int> > answer(rowLen, vector<int>(colLen, 0));

	pair<int, int> current = {MAX_VAL - 1, MAX_VAL - 1};
	pair<int, int> dir = {0, -1}; 
	pair<int, int> rowBounds = {0, MAX_VAL - 1};
	pair<int, int> colBounds = {0, MAX_VAL - 1};

	int num = MAX_VAL * MAX_VAL;

	while(num > 0) {
		if(current.first >= r1 && current.first <= r2 && current.second >= c1 && current.second <= c2)
		   answer[current.first - r1][current.second - c1] = num;
		   
		num--;

		int nextRow = current.first + dir.first;
		int nextCol = current.second + dir.second;
		if(nextRow < rowBounds.first) {
			dir.first = 0;
			dir.second = 1;
			colBounds.first++;
		}
		else if(nextRow > rowBounds.second) {
			dir.first = 0;
			dir.second = -1;
			colBounds.second--;
		}
		else if(nextCol < colBounds.first) {
			dir.first = -1;
			dir.second = 0;
			rowBounds.second--;
		}
		else if(nextCol > colBounds.second) {
			dir.first = 1;
			dir.second = 0;
			rowBounds.first++;
		}

		current.first += dir.first;
		current.second += dir.second;
	}

	function<int (int)> getNumberLength = [](int num){
		int cnt = 0;
		while(num > 0) {
			cnt++;
			num /= 10;
		}
		return cnt;
	};

	int maxLength = -1;
	for(int i = 0 ; i < rowLen ; i++) {
		for(int j = 0 ; j < colLen ; j++) {
			maxLength = max(maxLength, getNumberLength(answer[i][j]));
		}
	}

	for(int i = 0 ; i < rowLen ; i++) {
		for(int j = 0 ; j < colLen ; j++) {
			int curLength = getNumberLength(answer[i][j]);
			for(int i = 0 ; i < maxLength - curLength ; i++) cout << " ";
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

    return 0;
}