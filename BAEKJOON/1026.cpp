#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), [](auto a, auto b) {
		return a > b;
	});

	long long result = 0;
	for(int i = 0 ; i < n ; i++) result += (a[i] * b[i]);

	cout << result;

    return 0;
}