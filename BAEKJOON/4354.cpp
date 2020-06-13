#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPartialMatch(const string &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(true){
		string N;
		cin >> N;
		if(N == ".") break;

		vector<int> pi = getPartialMatch(N);

		if(pi[N.size() - 1] == 0 || pi[N.size() - 1] % (N.size() - pi[N.size() - 1])) cout << "1\n";
		else cout << N.size() / (N.size() - pi[N.size() - 1]) << "\n";
	}

	return 0;
}

vector<int> getPartialMatch(const string & N){
	vector<int> pi(N.size(), 0);
	
	int matched = 0;
  	for(int i = 1 ; i < N.size() ; i++){
		while(matched > 0 && N[i] != N[matched]) matched = pi[matched - 1];
		if(N[i] == N[matched]) pi[i] = ++matched;
	}

  	return pi;
}
