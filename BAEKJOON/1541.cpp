#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
	getline(cin, input);

	int result = 0;
	int sum = 0;
	int cur = 0;
	int state = 0;
	for(int i = 0 ; i < input.length() ; i++){		
		if(input[i] == '+'){
			if(state == 0) {
				result += cur;
			}
			else if(state == 1) {
				sum += cur;
			}
			cur = 0;
			// cout << result << " ";
		}
		else if(input[i] == '-'){
			if(state == 0){
				result += cur;
				state = 1;
			}
			else if(state == 1){
				sum += cur;
				result -= sum;
				sum = 0;
			}
			cur = 0;
			// cout << result << " ";
		}
		else{
			cur *= 10;
			cur += (input[i] - '0');
		}
	}

	if(state == 0){
		result += cur;
	}
	else{
		sum += cur;
		result -= sum;
	}

	cout << result;
    
    return 0;
}
