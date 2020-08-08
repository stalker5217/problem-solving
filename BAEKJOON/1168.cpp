#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
	cin >> n >> k;

	vector<int> yosef(n);
	for(int i = 1 ; i <= n ; i++) yosef[i-1] = i;


	int preIdx = 0;
	int curIdx;

	cout << "<";
	for(int i = 1 ; i <= n ; i++){
		int curIdx = (preIdx + k - 1) % yosef.size();
		cout << yosef[curIdx];
		if(i < n)  cout << ", ";
		yosef.erase(yosef.begin() + curIdx);
		preIdx = curIdx;
	}
	cout << ">";
	    
    return 0;
}