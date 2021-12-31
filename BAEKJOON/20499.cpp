#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int kill, death, assist;
	char slash;
	cin >> kill >> slash >> death >> slash >> assist;

	if(kill + assist  < death|| death == 0) cout << "hasu";
	else cout << "gosu";

	return 0;
}