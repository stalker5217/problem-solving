#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
	string b;
	cin >> a >> b;

	int longLength = a.size() > b.size() ? a.size() : b.size();

	int pre = 0;
	deque<int> answer;
	for(int i = 1 ; i <= longLength ; i++){
		int aaa = 0;
		int bbb = 0;

		if(a.size() >= i){
			aaa = a[a.size() - i] - '0';
		}

		if(b.size() >= i){
			bbb = b[b.size() - i] - '0';
		}

		int result = aaa + bbb + pre;
		pre = result / 10;
		answer.push_front(result % 10);
	}

	if(pre > 0) answer.push_front(pre);

	for(int i : answer){
		cout << i;
	}
    
    return 0;
}
