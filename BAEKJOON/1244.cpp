#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int switchCnt; cin >> switchCnt;
	vector<int> switchs(switchCnt + 1);
	for(int i = 1 ; i <= switchCnt ; i++) 
		cin >> switchs[i];

	int studentCnt; cin >> studentCnt;
	while(studentCnt--) {
		int sex, num;
		cin >> sex >> num;

		// 남학생
		if(sex == 1) {
			for(int i = num ; i <= switchCnt ; i += num) {
				switchs[i] ^= 1;
			}
		}
		// 여학생
		else if(sex == 2) {
			int left = num - 1;
			int right = num + 1;
			switchs[num] ^= 1;
			while(left > 0 && right <= switchCnt && switchs[left] == switchs[right]) {
				switchs[left] ^= 1;
				switchs[right] ^= 1;
				left--; right++;
			}
		}
	}

	for(int i = 1 ; i <= switchCnt ; i++) {
		cout << switchs[i];
		if(i % 20 == 0) cout << "\n";
		else cout << " ";
	}

	return 0;
}