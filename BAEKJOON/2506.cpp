#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt;
	cin >> cnt;

	int sum = 0;
	int curScore = 0;
	for(int i = 0 ; i < cnt ; i++){
		int answer;
		cin >> answer;
		if(answer) sum += ++curScore;
		else curScore = 0;
	}

    cout << sum;

    return 0;
}
