#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class mstack {
private:
	int ntop;
	int arr[10000];

public:
	mstack() {
		ntop = 0;
	}

	bool empty() {
		if (ntop == 0)
			return true;
		else
			return false;
	}

	void push(int n) {
		arr[ntop++] = n;
	}

	int pop() {
		ntop--;
		return arr[ntop];
	}

	int top() {
		return arr[ntop - 1];
	}

	int size() {
		return ntop;
	}
};


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	
	mstack mystack;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int a;
			cin >> a;
			getchar();

			mystack.push(a);
		}

		else if (command == "pop") {
			if (mystack.empty()) {
				cout << "-1\n";
			}
			else {
				cout << mystack.pop() << "\n";
			}
		}

		else if (command == "size") {
			cout << mystack.size() << "\n";
		}

		else if (command == "empty") {
			if (mystack.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}

		else if (command == "top") {
			if (mystack.empty()) {
				cout << "-1\n";
			}
			else { 
				cout << mystack.top() << "\n";
			}
		}
	}

	return 0;
}