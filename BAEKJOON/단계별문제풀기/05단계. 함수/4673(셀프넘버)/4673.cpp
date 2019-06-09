#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

int main(int argc, char** argv)
{
	bool arr[10001];
	memset(arr, true, sizeof(bool) * 10001);

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == true) {
			int temp = i;
			int newnum = i;
			while (true) {
				while (true) {
					newnum += temp % 10;
					if (temp / 10 == 0)
						break;
					else
						temp /= 10;
				}

				if (newnum > 10000)
					break;


				arr[newnum] = false;
				temp = newnum;

			}
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == true)
			printf("%d\n", i);
	}


	return 0;
}