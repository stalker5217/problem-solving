#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> a(n, 0); 
	vector<long long> b(n, 0);
	vector<long long> c(n, 0);
	vector<long long> d(n, 0);

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		cin >> b[i];
		cin >> c[i];
		cin >> d[i];
	}

	vector<long long> ab(n*n, 0);
	vector<long long> cd(n*n, 0);
	int idx = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			ab[idx] = a[i] + b[j];
			cd[idx] = c[i] + d[j];
			idx++;
		}
	}

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	int start = 0;
	int end = cd.size() - 1;
	long long answer = 0;
	while(start < ab.size() && end >= 0){
		long long sum = ab[start] + cd[end];
		 
		if(sum < 0) start++;
		else if(sum > 0) end--;
		else{
			long long abVal = ab[start];
			long long cdVal = cd[end];
			long long abCnt = 0, cdCnt = 0;
			while(start < ab.size() && ab[start] + cdVal == 0){
				start++;
				abCnt++;
			}
			while(end >= 0 && abVal + cd[end] == 0){
				end--;
				cdCnt++;
			}

			answer += (abCnt * cdCnt);
		}
	}
	
	cout << answer;

    return 0;
}