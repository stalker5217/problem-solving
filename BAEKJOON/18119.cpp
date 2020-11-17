#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int wordCnt, queryCnt;
	cin >> wordCnt >> queryCnt;
	
	int knownSet = (1 << 26) - 1;
	vector<int> wordSet;
	for(int i = 0 ; i < wordCnt ; i++){
		string word;
		cin >> word;
		
		int wordBit = 0;
		for(int i = 0 ; i < word.size() ; i++){
			int shift = word[i] - 'a';
			wordBit |= (1 << shift);
		}
		wordSet.push_back(wordBit);
	}

	for(int i = 0 ; i < queryCnt ; i++){
		int cmd;
		char alphabet;

		cin >> cmd >> alphabet;

		int shift = alphabet - 'a';
		// 잊는다
		if(cmd == 1) knownSet &= ~(1 << shift);
		// 기억한다
		else knownSet |= (1 << shift);

		int cnt = 0;
		for(int wordBit : wordSet){
			if(wordBit == (wordBit & knownSet)) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}