#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int a;
		int b;

		int arr[6];
		
		for(int i = 0 ; i < 6 ; i++){
			char a, b, colon;
			cin >> a >> b;

			if(i % 3 != 2){
				cin >> colon;
			}

			arr[i] = (a - '0') * 10 + (b - '0');
		}

		a = arr[0] * 60 * 60;
		a += arr[1] * 60;
		a += arr[2];

		b = arr[3] * 60 * 60;
		b += arr[4] * 60;
		b += arr[5];

		int baseline = 24 * 60 * 60;
		int diff = b - a;

		if(diff < 0){
			diff += baseline;
		}

		string result = "";
		int temp;

		// 시간
		temp = diff / (60 * 60);
		diff -= temp * 60 * 60;
		if(temp < 10)
			result.append("0");
		result.append(to_string(temp));
		result.append(":");
		
		// 분
		temp = diff / 60;
		diff -= temp * 60;
		if(temp < 10)
			result.append("0");
		result.append(to_string(temp));
		result.append(":");
		
		if(diff < 10)
			result.append("0");
		result.append(to_string(diff));

		cout << "#" << test_case << " " << result << "\n"; 
	}
	return 0;
}