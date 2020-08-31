#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > partialSum_2d(const vector<vector<int> > arr);
int gridSum(const vector<vector<int> > & psum, int x1, int y1, int x2, int y2);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, test_case;
	cin >> n >> test_case;
    vector<vector<int > > arr(n, vector<int>(n, 0));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> arr[i][j];
		}
	}

	vector<vector<int> > partialSum = partialSum_2d(arr);
	while(test_case--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << gridSum(partialSum, x1-1, y1-1, x2-1, y2-1) << "\n";
	}
    
    return 0;
}

vector<vector<int> > partialSum_2d(const vector<vector<int> > arr){
	vector<vector<int> > ret(arr.size(), vector<int>(arr[0].size(), 0));

	ret[0][0] = arr[0][0];
	for(int i = 1 ; i < ret.size() ; i++) ret[i][0] = ret[i-1][0] + arr[i][0];
	for(int i = 1 ; i < ret[0].size() ; i++) ret[0][i] = ret[0][i-1] + arr[0][i];

	for(int i = 1 ; i < ret.size() ; i++){
		for(int j = 1 ; j < ret[i].size() ; j++){
		ret[i][j] = ret[i-1][j] + ret[i][j-1] - ret[i-1][j-1] + arr[i][j]; 
		}
	}
	
	return ret;
}

int gridSum(const vector<vector<int> > & psum, int x1, int y1, int x2, int y2){
	int ret = psum[x2][y2];

	if(y1 > 0) ret -= psum[x2][y1-1];
	if(x1 > 0) ret -= psum[x1-1][y2];
	if(y1 > 0 && x1 > 0) ret += psum[x1-1][y1-1];

	return ret;
}