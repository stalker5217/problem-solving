#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cmd;
	cin >> cmd;

	string result = (cmd == 0) ? "YONSEI" : "Leading the Way to the Future";
	cout << result;
    
    return 0;
}
