#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 1 ; i <= s.size() ; i++){
        char maxChar = 0;
        
        for(int j = i - 1 ; j > 0 ; j--){
            if(s[j] > s[j-1]) swap(s[j], s[j-1]);
			else break;
        }
		cout << s << endl;
    }

	answer = s;
    
    return answer;
}

int main(){
	cout << solution("Zbcdefg"); // gfedcbZ
}