#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;
	for(int t = 0 ; t < test_case ; t++){
		string a, b;
		cin >> a >> b;

		int hammingDistance = 0;
		for(int i = 0 ; i < a.size() ; i++){
			if(a[i] != b[i]) hammingDistance++;
		}

		cout << "Hamming distance is " << hammingDistance << ".\n";
	}
    
    return 0;
}
