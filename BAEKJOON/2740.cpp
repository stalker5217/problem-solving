#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int a_n, a_m;
	cin >> a_n >> a_m;
	vector<vector<int> > a(a_n, vector<int>(a_m, 0));
	for(int i = 0 ; i < a_n ; i++){
		for(int j = 0 ; j < a_m ; j++){
			cin >> a[i][j];
		}
	}

	int b_n, b_m;
	cin >> b_n >> b_m;
	vector<vector<int> > b(b_n, vector<int>(b_m, 0));
	for(int i = 0 ; i < b_n ; i++){
		for(int j = 0 ; j < b_m ; j++){
			cin >> b[i][j];
		}
	}

	vector<vector<int> > result(a_n, vector<int>(b_m, 0));
	for(int i = 0 ; i < a_n ; i++){
		for(int j = 0 ; j < b_m ; j++){
			for(int k = 0 ; k < a_m ; k++){
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for(int i = 0 ; i < a_n ; i++){
		for(int j = 0 ; j < b_m ; j++){
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
    
    return 0;
}