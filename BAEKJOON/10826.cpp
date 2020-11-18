#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BigInteger{
	vector<int> numArr;

	BigInteger(){}

	BigInteger(string input){
		for(int i = input.size() - 1 ; i >= 0 ; i--){
			int value = input[i] - '0';
			numArr.push_back(value);
		}
	}

	BigInteger operator+(const BigInteger & ref){
		BigInteger ret;
		int longLength = max(numArr.size(), ref.numArr.size());
		int remain = 0;
		for(int i = 0 ; i < longLength ; i++){
			int sum;
			if(i < numArr.size() && i < ref.numArr.size()) sum = numArr[i] + ref.numArr[i] + remain;
			else if(i < numArr.size()) sum = numArr[i] + remain;
			else sum = ref.numArr[i] + remain;
			
			if(sum >= 10){
				remain = 1;
				sum %= 10;
			}
			else remain = 0;
	
			ret.numArr.push_back(sum);
		}
		if(remain) ret.numArr.push_back(remain);

		return ret;
	}

	void print(){
		for(int i = numArr.size() - 1 ; i >= 0 ; i--){
			cout << numArr[i];
		}
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	BigInteger fibo[10001];
	fibo[0] = BigInteger("0");
	fibo[1] = BigInteger("1");
	for(int i = 2 ; i <= n ; i++){
		fibo[i] = fibo[i-1] + fibo[i-2];
	}

	fibo[n].print();
	
    return 0;
}