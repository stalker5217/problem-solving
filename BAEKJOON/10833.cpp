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

	int N;
	cin >> N;
   	int sum = 0 ;
   	for(int i = 0 ; i < N ; i++){
		int a, b;
		cin >> a >> b;
		sum += b % a;
   	}
    
	cout << sum;

    return 0;
}
