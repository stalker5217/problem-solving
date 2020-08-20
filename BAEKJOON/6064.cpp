#define DEBUG 0
#define LOG(string) cout << string

#define MMAX 102

#include <iostream>
#include <cmath>

using namespace std;

int gcd(const int &, const int &);
int lcm(const int &, const int &);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	cin >> test_case;
	
	while(test_case--){
		int N, M;
		cin >> N >> M;

		int x = 1, y = 1, a, b;
		cin >> a >> b;

		int answer = -1;
		int mmax = lcm(N, M);
		
		for(int i = 1 ; i <= mmax ; ){
			if(x == a && y == b){
				answer = i;
				break;
			}
			else if(x == a){
				y = (y + N) % M > 0 ? (y + N) % M : M;
				i += N;
			}
			else{
				x = (x < N) ? (x + 1) : 1;
				y = (y < M) ? (y + 1) : 1;
				i++;
			}
		}

		cout << answer << "\n";
	}

    return 0;
}

int gcd(const int & a, const int & b){
	return (b == 0) ? a : gcd(b, a % b);
}

int lcm(const int & a, const int & b){
	int g = gcd((a > b) ? a : b, (a < b) ? a : b);
	return a * b / g;
}