#include <iostream>
#include <string>

using namespace std;

char result[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string input, bomb;
	cin >> input >> bomb;

	int idx = 0;
	char bombLastChar = bomb[bomb.length() - 1];
	for(int i = 0 ; i < input.length() ; i++){
		if(input[i] == bombLastChar && idx - bomb.length() + 1 >= 0){
			bool isBomb = true;
			for(int a = 0 ; a < bomb.length() - 1; a++){
				if(result[idx - bomb.length() + 1 + a] != bomb[a]){
					isBomb = false;
					break;
				}
			}

			if(isBomb) idx = idx - bomb.length() + 1;
			else result[idx++] = input[i];
		}
		else{
			result[idx++] = input[i];
		}
	}

	if(idx == 0) cout << "FRULA";
	else{
		result[idx++] = 0;
		cout << result;
	}

	return 0;
}