#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	stack<pair<int, int> > st;
	long long answer = 0;

	int n; cin >> n;
	while(n--) {
		int height; cin >> height;

		int sameCnt = 1;
		while(!st.empty()) {
			if(height > st.top().first) {
				answer += st.top().second;
				sameCnt = 1;
				st.pop();
			}
			else if(height == st.top().first) {
				answer += st.top().second;
				sameCnt = st.top().second + 1;
				st.pop();
			}
			else {
				answer++;
				break;
			}
		}

		st.push({height, sameCnt});
	}

	cout << answer;

    return 0;
}