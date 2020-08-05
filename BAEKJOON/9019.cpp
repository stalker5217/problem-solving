#define DEBUG 0
#define LOG(string) cout << string

#define D 0
#define S 1
#define L 2
#define R 3

#include <iostream>
#include <queue>

using namespace std;

int cmd(int, int);
string bfs(const int &, const int &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	cin >> t;
	while(t--){
		int start, target;
		cin >> start >> target;
		cout << bfs(start, target) << "\n";
	}
    
    return 0;
}

int cmd(int n, int c){
	if (c == D) return (n * 2) % 10000;
	else if(c == S) return (n == 0) ? 9999 : n-1;
	else if(c == L) return (n % 1000) * 10 + (n / 1000);
	else if(c == R) return (n % 10) * 1000 + (n / 10);
	
    // prevent warning
    else return -1;
}

string bfs(const int & start, const int & target){
	bool visit[10000] = {false, };
    const char cmdChar[4] = {'D', 'S', 'L', 'R'};

	queue<pair<int, string> > q;
	q.push({start, ""});
	visit[start] = true;
	
	while(!q.empty()){
		int cur = q.front().first;
		string path = q.front().second;
		q.pop();
        // cout << path << endl;
		if(cur == target) return path;

		for(int i = 0 ; i < 4 ; i++){
			int next = cmd(cur, i);
			if(!visit[next]){
				visit[next] = true;
				q.push({next, path + cmdChar[i]});
			}
		}
	}
    
    // prevent warning
	return "!";
}