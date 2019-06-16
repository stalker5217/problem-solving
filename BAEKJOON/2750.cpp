#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

void insertion_sort(int *arr, int size){
	for (int i = size - 1; i >= 0; i--) {
		for (int j = i; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
			else
				break;
				

		}
	}
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	int arr[1000];


	for (int i = 0; i < t; i++)
		cin >> arr[i];
	
	insertion_sort(arr, t);

	for (int i = 0; i < t; i++)
		cout << arr[i] << endl;


	return 0;
}