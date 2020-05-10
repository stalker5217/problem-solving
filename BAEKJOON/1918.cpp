#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <stack>

using namespace std;

void removeBracket(stack<char> &, string &);
void moveOperator(char, stack<char> &, string &);
bool cmpPrioriy(char a, char b);
int getPriority(char a);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    stack<char> opStack;
    string expr = "";
    for(int i = 0 ; i < input.length() ; i++){
        char cur = input[i];

        switch(cur){
            case '(':
                opStack.push(cur);
                break;
            case ')':
                removeBracket(opStack, expr);
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                moveOperator(cur, opStack, expr);
                opStack.push(cur);
                break;
            default:
                expr += cur;
        }
    }

    while(!opStack.empty()){
        expr += opStack.top();
        opStack.pop();
    }

    cout << expr;

    return 0;
}

void removeBracket(stack<char> & opStack, string & expr){
    while(true){
        if(opStack.top() == '('){
            opStack.pop();
            return;
        }
        else{
            expr += opStack.top();
            opStack.pop();
        }
    }

}

void moveOperator(char cur, stack<char> & opStack, string & expr){
    while(!opStack.empty() && cmpPrioriy(cur, opStack.top())){
        expr += opStack.top();
        opStack.pop();
    }
}

bool cmpPrioriy(char a, char b){
    return getPriority(a) <= getPriority(b) ? true : false;
}

int getPriority(char a){
    switch(a){
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}