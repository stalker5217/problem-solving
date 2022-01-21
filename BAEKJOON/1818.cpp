#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> books(n);
	for(int i = 0 ; i < n ; i++) cin >> books[i];

	vector<int> lis;
	lis.push_back(0);
	for(int book : books) {
		if(lis.back() < book) lis.push_back(book);
		else {
			int replaceIdx = lower_bound(lis.begin(), lis.end(), book) - lis.begin();
			lis[replaceIdx] = book;
		}
	}

	cout << n + 1 - lis.size();

	return 0;
}