#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<int> positions(n);
	for(int i = 0 ; i < n ; i++) cin >> positions[i];
	sort(positions.begin(), positions.end());

	int stickerPos = -1000;
	int stickerCnt = 0;
	for(auto position : positions) {
		if(position - (l - 1) > stickerPos) {
			stickerPos = position;
			stickerCnt++;
		}
	}

	cout << stickerCnt;

	return 0;
}