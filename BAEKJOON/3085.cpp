#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	
	vector<vector<char> > arr(n, vector<char>(n, 0));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> arr[i][j];
		}
	}

	function<int (int, int)> checkCnt = [&](int row, int col) {
		char cur = arr[row][col];

		int rowCnt = 1;
		for(int i = row + 1; i < n ; i++) {
			if(arr[i][col] == cur) rowCnt++;
			else break;
		}

		for(int i = row - 1 ; i >= 0 ; i--) {
			if(arr[i][col] == cur) rowCnt++;
			else break;
		}

		int colCnt = 1;
		for(int i = col + 1 ; i < n ; i++) {
			if(arr[row][i] == cur) colCnt++;
			else break;
		}

		for(int i = col - 1 ; i < n ; i--) {
			if(arr[row][i] == cur) colCnt++;
			else break;
		}

		return max(rowCnt, colCnt);
	};

	int maxCnt = -1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n - 1 ; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			
			maxCnt = max(maxCnt, checkCnt(i, j));
			maxCnt = max(maxCnt, checkCnt(i, j + 1));
	
			swap(arr[i][j], arr[i][j + 1]);
		}
	}

	for(int i = 0 ; i < n - 1 ; i++) {
		for(int j = 0 ; j < n ; j++) {
			swap(arr[i][j], arr[i + 1][j]);

			maxCnt = max(maxCnt, checkCnt(i, j));
			maxCnt = max(maxCnt, checkCnt(i + 1, j));

			swap(arr[i][j], arr[i + 1][j]);
		}
	}

	cout << maxCnt;

	return 0;
}