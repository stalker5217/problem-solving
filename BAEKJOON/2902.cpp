#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
	cin >> input;

	char charArr[101];
	strcpy(charArr, input.c_str());
	char * token = strtok(charArr, "-");
	while(token != nullptr){
		cout << token[0];
		token = strtok(nullptr, "-");
	}
    
    return 0;
}
