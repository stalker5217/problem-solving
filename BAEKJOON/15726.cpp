#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
	cin >> a >> b >> c;

	long long case1 = (long long)a * b / c;
	long long case2 = (long long)a * c / b;
	long long answer = (case1 > case2) ? case1 : case2;

	cout << answer;

    return 0;
}
