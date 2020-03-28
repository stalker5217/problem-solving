#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void combination(int);

int K, N;
int myMax = -987654321;
vector<int> arr;
vector<int> choice;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> K >> N;

	for(int i = 0 ; i < K ; i++){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	combination(0);

	cout << myMax;

    return 0;
}

void combination(int offset){
	if(choice.size() == 3){
		int sum = 0;

		for(int i = 0 ; i < choice.size() ; i++){
			sum += choice[i];
		}

		if(sum > N){
			return;
		}
		else{
			myMax = (myMax > sum) ? myMax : sum;
		}

		return;
	}
	
	for(int i = offset ; i < K ; i++){
		choice.push_back(arr[i]);
		combination(i+1);
		choice.pop_back();
	}
}
