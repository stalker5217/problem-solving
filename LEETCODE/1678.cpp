#include <string>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string answer = "";
        int i = 0 ;
        while (i < command.size()) {
            if(command[i] == 'G') {
                answer += 'G';
                i++;
            }
            else if (command[i] = '(') {
                if (command[i + 1] == ')') {
                    answer += 'o';
                    i += 2;
                }
                else {
                    answer += "al";
                    i += 4;
                }
            }
        }
        
        return answer;
    }
};