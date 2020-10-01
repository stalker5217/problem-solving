#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int fullCheck(const int &, const int &, const string &);
int tailCheck(const int &, const int &, const string &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
	string m;
	cin >> n >> s >> m;

	int isMatched = 0;
	int i = 0;
	int answer = 0;
	while(i <= m.size() - (2 * n + 1)){
		if(isMatched >= 0) isMatched = fullCheck(i, n, m);
		else isMatched = tailCheck(i, n, m);

		if(isMatched < 0){
			i += 2;
			answer++;
		}
		else if(isMatched == 0) i += (isMatched + 1);
		else i += isMatched;
	}
	
	cout << answer;
	
    return 0;
}

int fullCheck(const int & start, const int & n, const string & m){
	for(int i = 0 ; i < (2 * n) + 1 ; i++){
		if(i % 2 == 0 && m[start + i] != 'I'){
			return i;
		}
		else if(i % 2 == 1 && m[start + i] != 'O'){
			return i;
		}
	}

	return -1;
}

int tailCheck(const int & start, const int & n, const string & m){
	if(m[start + (2 * n - 1)] != 'O') return (2 * n - 1);
	else if(m[start + (2 * n)] != 'I') return (2 * n);

	return -1;
}