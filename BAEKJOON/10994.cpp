#include <iostream>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	function<void (int, int)> firstLine = [](int n, int indent) {
			for(int i = 0 ; i < indent ; i++) cout << "* ";
			for(int i = 0 ; i < n * 4 - 3 ; i++) cout << "*";
			for(int i = 0 ; i < indent ; i++) cout << " *";
			cout << "\n";
		};

	function<void (int, int)> secondLine = [](int n, int indent) {
		for(int i = 0 ; i < indent ; i++) cout << "* ";
		cout << "*";
		for(int i = 0 ; i < n * 4 - 5 ; i++) cout << " ";
		cout << "*"; 
		for(int i = 0 ; i < indent ; i++) cout << " *";
		cout << "\n";
	};

	function<void (int, int)> printStart = [&](int n,  int indent) {
		if(n == 0) return;
		else if(n == 1) {
			for(int i = 0 ; i < indent ; i++) cout << "* ";
			cout << "*";
			for(int i = 0 ; i < indent ; i++) cout << " *";
			cout << "\n";
			
			return;
		}

		firstLine(n, indent);
		secondLine(n, indent);
		printStart(n - 1, indent + 1);
		secondLine(n, indent);
		firstLine(n, indent);
	};

	printStart(n, 0);
}