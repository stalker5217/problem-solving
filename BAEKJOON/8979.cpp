#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct __Country {
	int num;
	int gold;
	int silver;
	int bronze;
} Country;

int main() {
	int n, k;
	cin >> n >> k;

	vector<Country> arr(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> arr[i].num;
		
		cin >> arr[i].gold;
		cin >> arr[i].silver;
		cin >> arr[i].bronze;
	}

	sort(arr.begin(), arr.end(), [&](auto a, auto b) {
		if(a.gold != b.gold) return a.gold > b.gold;
		else if(a.silver != b.silver) return a.silver > b.silver;
		else return a.bronze > b.bronze;
	});

	int rank = 0;
	int add = 1;
	Country prevScore;
	prevScore.gold = -1;
	prevScore.silver = -1;
	prevScore.bronze = -1;
	for(auto cur : arr) {
		if((prevScore.gold == cur.gold && prevScore.silver == cur.silver && prevScore.bronze == cur.bronze)) add++;
		else {
			rank += add;
			add = 1;
		}
		
		prevScore.gold = cur.gold;
		prevScore.silver = cur.silver;
		prevScore.bronze = cur.bronze;

		if(cur.num == k) {
			cout << rank;
			break;
		}
	}

	return 0;
}