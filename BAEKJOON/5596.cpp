#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i1, m1, s1, e1;
	int i2, m2, s2, e2;

	cin >> i1 >> m1 >> s1 >> e1;
	cin >> i2 >> m2 >> s2 >> e2;

	int sum1 = i1 + m1 + s1 + e1;
	int sum2 = i2 + m2 + s2 + e2;

	int ans = (sum1 >= sum2) ? sum1 : sum2;

	cout << ans;
    
    return 0;
}
