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

	int size;
	string N;
	cin >> size >> N;
	vector<int> pi = getPartialMatch(N);
	
	cout << size - pi[size - 1];

	return 0;
}

vector<int> getPartialMatch(const string & N){
  int m = N.size();
  vector<int> pi(m, 0);

  // KMP algorithm으로 index 1부터 자기 자신 탐색 시작
  int begin = 1, matched = 0;
  while(begin + matched < m){
    if(N[begin + matched] == N[matched]){
      ++matched;
      pi[begin + matched - 1] = matched;
    }
    else{
      if(matched == 0) ++begin;
      else{
        // 이 시점에서 matched - 1는 항상 계산되어 있음이 보장된다.
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return pi;
}