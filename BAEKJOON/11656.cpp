#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s;
	cin >> s;

	vector<string> arr;
	for(int i = 0 ; i < s.size() ; i++) arr.push_back(s.substr(i, s.size() - i));
	sort(arr.begin(), arr.end());

	for(string s : arr) cout << s << "\n";

    return 0;
}