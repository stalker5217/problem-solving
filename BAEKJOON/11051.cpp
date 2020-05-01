#include <iostream>
#include <vector>

#define MODVAL 10007

using namespace std;

int factorial[1001];
void make_factorial();
int fermatInverse(int n, int modVal);

int main()
{
	int n, k;
	cin >> n >> k;

	if(k == 0 || k == n){
		cout << 1 << endl;
		return 0;
	}

	make_factorial();
	int answer = (factorial[n] * fermatInverse(factorial[k] * factorial[n-k] % MODVAL, MODVAL)) % MODVAL;
	
	cout << answer << endl;

	return 0;
}

void make_factorial(){
	factorial[0] = 0;
	factorial[1] = 1;
	for(int i = 2; i <= 1000 ; i++) factorial[i] = (factorial[i-1] * i) % MODVAL;
}

int fermatInverse(int n, int modVal){
	int powGoal = modVal - 2;

	int ret = n;
	int pow = 1;
	while(1){
		if(pow * 2 <= powGoal){
			pow *= 2;
			ret = (ret * ret) % modVal;
		}
		else{
			pow += 1;
			ret = (ret * n) % modVal;
		}

		if(powGoal == pow) break;
	}

	return ret;
}