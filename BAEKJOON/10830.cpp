#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5;
int n;

vector<vector<long long > > mulMatrix(vector<vector<long long > >, vector<vector<long long > >);

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long b;
	cin >> n >> b;

	vector<vector<long long > > matrix(n, vector<long long>(n, 0));
	vector<vector<long long > > answer(n, vector<long long>(n, 0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> matrix[i][j];
		}
		answer[i][i] = 1;
	}

	for(; b > 0 ; b = b / 2){
		if(b % 2) answer = mulMatrix(answer, matrix);
		matrix = mulMatrix(matrix, matrix);
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

vector<vector<long long > > mulMatrix(vector<vector<long long > > a, vector<vector<long long > > b){
	vector<vector<long long > > ret(n, vector<long long>(n, 0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				ret[i][j] += (a[i][k] * b[k][j]) % 1000;
			}
			ret[i][j] %= 1000;
		}
	}

	return ret;
}