#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int n;
	cin >> n;
	
	int arr[10000];
	int index = 1;
	arr[1] = 1;
	int dist;

	while (true) {
		if (n > arr[index]) {
			index++;
			arr[index] = 3 * index * (index - 1) + 1;
		}
		else {
			dist = index;
			break;
		}
	}

	cout << dist;

	return 0;
}

// 3n(n-1) + 1