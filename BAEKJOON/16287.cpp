#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int weight, n;
	cin >> weight >> n;
	vector<int> parcels(n);
	for(int i = 0 ; i < n ; i++) cin >> parcels[i];

	vector<bool> possibles(weight + 1, false);
	bool possible = false;
	for(int i = 0 ; i < n - 1; i++) {
		for(int j = i + 1 ; j < n ; j++) {
			int cd = parcels[i] + parcels[j];
			if(cd > weight) continue;
			if(possibles[weight - cd]) {
				possible = true;
				break;
			}
		}

		if(possible) break;
		for(int j = 0 ; j < i ; j++) {
			int ab = parcels[i] + parcels[j];
			if(ab <= weight) possibles[ab] = true;
		}
	}

	if(possible) cout << "YES";
	else cout << "NO";

	return 0;
}