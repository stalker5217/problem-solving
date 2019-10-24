#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int * arr = new int[N];
	for(int i = 0 ; i < N ; i++){
		cin >> arr[i];
	}

	for(int i = 0 ; i < M ; i++){
		int myBegin, myEnd;
		cin >> myBegin >> myEnd;

		int minVal = 1000000001;
		int maxVal = 0;
		for(int k = myBegin - 1 ; k < myEnd ; k++){
			if(minVal > arr[k]){
				minVal = arr[k];
			}

			if(maxVal < arr[k]){
				maxVal = arr[k];
			}
		}
		
		cout << minVal << " " << maxVal << "\n";
		
	}

	delete arr;
    return 0;
}
