#define DEBUG 0
#define LOG(string) cout << string
#define MOD 1000000
#define ll long long

#include <iostream>
#include <vector>

using namespace std;

vector<vector<ll> > mulMatrix(const vector<vector<ll> > & a, const vector<vector<ll> > & b){
	vector<vector<ll> > result(a.size(), vector<ll>(b[0].size(), 0));

	for(int i = 0 ; i < a.size() ; i++){
		for(int j = 0 ; j < b[0].size() ; j++){
			for(int k = 0 ; k < a[0].size() ; k++){
				result[i][j] += (a[i][k] * b[k][j]) % MOD;
			}
			result[i][j] %= MOD;
		}
	}

	return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
	cin >> n;

	vector<vector<ll> > base(2, vector<ll>(2, 0));
	vector<vector<ll> > answer(2, vector<ll>(2, 0));
	base[0][0] = 1; answer[0][0] = 1;
	base[0][1] = 1; answer[0][1] = 0;
	base[1][0] = 1; answer[1][0] = 0;
	base[1][1] = 0; answer[1][1] = 1;

	while(n > 0){
		if(n % 2) answer = mulMatrix(answer, base);
		base = mulMatrix(base, base);
		n /= 2;
	}

	cout << answer[1][0] % MOD;
    
    return 0;
}
