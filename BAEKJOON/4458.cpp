#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cctype>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_case;
	cin >> test_case;
	
	char temp[31];
	cin.getline(temp, 31);
	for(int t = 0 ; t < test_case ; t++){
		char str[31];
		cin.getline(str, 31);

		str[0] = toupper(str[0]);
		cout << str << "\n";
	}
}