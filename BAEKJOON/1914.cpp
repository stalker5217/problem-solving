#include <iostream>
#include <functional>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

	string answer = to_string(pow(2, n));
	answer = answer.substr(0, answer.find('.'));
	answer[answer.size() - 1]--;
	cout << answer << "\n";

	if(n <= 20) {
		function<void (int, int, int, int)> hanoi = [&](int n, int from, int to, int by) {
			if(n == 1) cout << from << " " << to <<  "\n";
			else {
				hanoi(n - 1, from, by, to);
				cout << from << " " << to <<  "\n";
				hanoi(n - 1, by, to, from);	
			}
		};

		hanoi(n, 1, 3, 2);
	}
	
    return 0;
}