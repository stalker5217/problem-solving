#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmpSearch(const string &, const string &);
vector<int> getPartialMatch(const string &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string H;
	string N;
    getline(cin, H);
	getline(cin, N);

	vector<int> ret = kmpSearch(H, N);
	cout << ret.size() << "\n";
	for(int idx : ret) cout << idx + 1 << "\n";
    
	return 0;
}

vector<int> kmpSearch(const string & H, const string & N){
  int n = H.size();
  int m = N.size();

  // pi 정보
  vector<int> ret;
  vector<int> pi = getPartialMatch(N);

  int begin = 0;
  int matched = 0;

  while(begin <= n - m){
    // matched index에서 서로 일치하는 경우
    if(matched < m && H[begin+matched] == N[matched]){
      ++matched;

      // 전체 탐색에 성공한 경우
      if(matched == m){
        ret.push_back(begin);
      }
    }
    else{
      // matched가 0인 경우에는 예외로 다음 칸에서 탐색
      if(matched == 0) ++begin;
      else{
        // pi 정보로 다음 promising한 위치 잡기
        begin += matched - pi[matched-1];
        // 시작 위치를 옮겨도 이미 pi[matched-1]만큼은 일치함. 
        matched = pi[matched-1];
      }
    }
  }

  return ret;
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