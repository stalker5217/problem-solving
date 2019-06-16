#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int T;
	cin >> T;

	for(int test_case = 1 ; test_case <= T ; ++test_case){
		int arr[10];
		memset(arr, 0, 10 * sizeof(int));

		int target;
		cin >> target;

		while(true){
			if(target == 0)
				break;

			arr[target % 10] = 1;
			target /= 10;
		}

		int result = 0;
		for(int i = 0 ; i < 10 ; i++){
			if(arr[i] > 0)
				++result;
		}

		cout << "#" << test_case << " " << result << "\n";
	}
}