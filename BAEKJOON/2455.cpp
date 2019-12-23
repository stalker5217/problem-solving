#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __inOut{
	int out;
	int in;
} inOut;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Algorithm
    vector<inOut> inOutVector;
	for(int i = 0 ; i < 4 ; i++){
		int in, out;
		cin >> out >> in;
		inOut temp;
		temp.out = out;
		temp.in = in;
		inOutVector.push_back(temp);
	}

	int mMax = -1;
	int sum = 0;
	for(int i = 0 ; i < 4 ; i++){
		sum -= inOutVector[i].out;
		sum += inOutVector[i].in;

		if(sum > mMax){
			mMax = sum;
		}
	}

	cout << mMax;

    return 0;
}
