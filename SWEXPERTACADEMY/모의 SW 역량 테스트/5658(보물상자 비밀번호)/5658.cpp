#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K; // Digit 수, 순위

		cin >> N >> K;
		string str;
		cin >> str;


		vector<int> arr;
		// 스트링 배열화
		for (int i = 0; i < N; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				arr.push_back(str[i] - '0');
			}

			else {
				arr.push_back(str[i] - 'A' + 10);
			}
		}

		int d;// 자릿수
		d = N / 4;
		int hex = 1; // 16진수 10진수화

		for (int i = 0; i < d - 1; i++)
			hex *= 16;

		// 값 구하기.
		vector<int> val;

		for (int i = 0; i < d; i++) {
			// 현재 배열에서 값 구하기.
			int value = 0;
			int unit = hex;
			for (int j = 1; j <= N; j++) {
				value += arr[j - 1] * unit;

				if (j%d == 0) {
					// 중복 값은 삽입하지 않는다.
					vector<int>::iterator isExist = find(val.begin(), val.end(), value);
					if (isExist == val.end()) {
						val.push_back(value);
					}
					value = 0;
					unit = hex;
				}
				else
					unit /= 16;
			}

			int temp = arr.back();
			arr.pop_back();
			arr.insert(arr.begin(), temp);
		}

		sort(val.begin(), val.end(), greater<int>());

		cout << "#" << test_case << " " << val[K - 1] << endl;


		        /*for (int i = 0; i < val.size(); i++)
				            cout << val[i] << endl;*/
	}
	return 0;
}