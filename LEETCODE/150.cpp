#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = operand.top();
                operand.pop();
                
                int a = operand.top();
                operand.pop();
                
                switch(token[0]) {
                    case '+':
                        operand.push(a + b);
                        break;
                    case '-':
                        operand.push(a - b);
                        break;
                    case '*':
                        operand.push(a * b);
                        break;
                    case '/':
                        operand.push(a / b);
                        break;
                }
            } 
            else {
                operand.push(stoi(token));    
            }
        }
        
        return operand.top();
    }
};