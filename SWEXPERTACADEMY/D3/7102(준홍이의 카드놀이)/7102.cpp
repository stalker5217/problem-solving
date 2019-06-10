#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int T;
	cin >> T;

	for(int test_case = 1 ; test_case <= T ; ++test_case){
		int N, M;
		cin >> N >> M;

		int arr[41];
		memset(arr, 0, 41 * sizeof(int));

		for(int i = 1 ; i <= N ; i++){
			for(int j = 1 ; j <= M ; j++){
				arr[i+j]++;
			}
		}

		int maxVal = 0;
		for(int i = 2 ; i < 41 ; i++){
			maxVal = (maxVal > arr[i]) ? maxVal : arr[i];
		}

		cout << "#" << test_case << " ";
		for(int i = 2 ; i < 41 ; i++){
			if(arr[i] == maxVal)
				cout << i << " ";
		}
		cout << "\n";
	}
}