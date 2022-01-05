#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int youngest, middle;
	cin >> youngest >> middle;

	cout << 2 * middle - youngest;

	return 0;
}