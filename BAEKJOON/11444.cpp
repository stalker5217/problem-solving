#define DEBUG 1
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long> > multiply(vector<vector<long long> > m1, vector<vector<long long> > m2);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long n;
	cin >> n;

	vector<vector<long long> > answer = {{1, 0}, {0, 1}};
	vector<vector<long long> > base = {{1, 1}, {1, 0}};

	while(n > 0){
		if(n % 2 == 1) answer = multiply(answer, base);
		base = multiply(base, base);
		n /= 2;
	}

	cout << answer[0][1];

    return 0;
}

vector<vector<long long> > multiply(vector<vector<long long> > m1, vector<vector<long long> > m2){
	vector<vector<long long> > ret(2, vector<long long>(2, 0));

	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 2 ; j++){
			for(int k = 0 ; k < 2 ; k++){
				ret[i][j] += m1[i][k] * m2[k][j];
			}
			ret[i][j] %= 1000000007;
		}
	}

	return ret;
}