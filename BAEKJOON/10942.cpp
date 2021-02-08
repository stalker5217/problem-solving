#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	vector<int> arr(n+1, 0);
	for(int i = 1; i <= n ; i++){
		cin >> arr[i];
	}

	vector<vector<bool> > isPalindrome(n+1, vector<bool>(n+1, false));
	for(int i = 1 ; i <= n ; i++) isPalindrome[i][i] = true;
	for(int i = 1 ; i < n ; i++) if(arr[i] == arr[i+1]) isPalindrome[i][i+1] = true;

	for(int j = 1 ; j <= n ; j++){
		for(int i = 1 ; i + j <= n ; i++){
			if(isPalindrome[i+1][i+j-1] && arr[i] == arr[i+j]) isPalindrome[i][i+j] = true;
		}
	}

	int queryCnt;
	cin >> queryCnt;
	for(int i = 0 ; i < queryCnt ; i++){
		int start, end;
		cin >> start >> end;
		cout << isPalindrome[start][end] << "\n";
	}
    
    return 0;
}