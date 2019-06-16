#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	vector<int> dataSet;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		dataSet.push_back(a);
	}

	int stackMax = 0;
	stack<int> st;
	vector<char> seq;
	for(int t = 0 ; t < n ; t++){
		if (stackMax < dataSet[t]) {
			for (int i = stackMax + 1; i <= dataSet[t]; i++) {
				st.push(i);
				seq.push_back('+');
				stackMax = i;
			}

			st.pop();
			seq.push_back('-');
		}

		else {
			int top = st.top();
			if (top == dataSet[t]) {
				st.pop();
				seq.push_back('-');
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	for (vector<char>::iterator iter = seq.begin(); iter != seq.end(); iter++) {
		cout << *iter << "\n";
	}

	return 0;
}